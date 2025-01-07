#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "tcpconnect.h"
#include "addressUtils.h"
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include "errors.h"
#include <fcntl.h>

int socketCreation(){
	int socketFD = socket(AF_INET,SOCK_STREAM,0);
	if(socketFD < 0){  
		puts("Socket Creation Failed.");
	}else{
		//setSocketNonBlocking(socketFD);
		return socketFD;
	}
}

void timeoutHandler(int ignored){}

int addressValidation(TargetIp ip,TargetAddrIPv4 *targetAddr){
	int rtnVal = inet_pton(AF_INET,ip,&targetAddr->sin_addr.s_addr);
	if(rtnVal == 0 ){
		puts("The IP Address was Invalid");
		exit(EXIT_FAILURE);	
	}else if(rtnVal < 0){
		puts("There was an error converting the IP Address");	
		exit(EXIT_FAILURE);
	}else{
		return 1;
	}
}

void setSocketNonBlocking(int socketFD){
	int non = fcntl(socketFD,F_SETFL,O_NONBLOCK);
	if(fcntl(socketFD,F_SETFL,O_NONBLOCK) < 0){
		perror("fcntl failed");
		exit(EXIT_FAILURE);
	}else{
		printf("%d",non);
	}			
}

int socketConnection(TargetIp ip,int *portsArray){
	//create the sigaction struct to handle hungup connect
	struct sigaction handler;
	memset(&handler,0,sizeof(handler));
	//the function that will be called when SIGALRM is raised
	handler.sa_handler = timeoutHandler;
	//creates an empty set of signals that should be blocked
   	sigemptyset(&handler.sa_mask);
	//no special flags are used
	handler.sa_flags = 0;
	//look at man page =>registers handler function with kernel for sigalrm
	//0 on success, -1 failure and errno set
	if(sigaction(SIGALRM, &handler,NULL) < 0){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	TargetAddrIPv4 targetAddr;
	memset(&targetAddr, 0, sizeof(targetAddr));
	targetAddr.sin_family = AF_INET;
	addressValidation(ip,&targetAddr);
	int portStart = portsArray[0];
	int portEnd = portsArray[1];
	for(int i = portStart; i <= portEnd; i++){
		int socketFD = socketCreation();
		setSocketNonBlocking(socketFD);
		int port = i;
		targetAddr.sin_port = htons(port);
		if(connect(socketFD,(struct sockaddr *) &targetAddr,sizeof(targetAddr)) != -1){
			printf("Connection Success for port %d.\n",port);
		}else{
			alarm(5);
			int num = 3;
 			close(socketFD);
			testFoo(num);
		//	printf("Connection Failed for port %d.\n",port);
		}

	}
}
//rename function to portSplit for clarity
void ports(int *portsArray,char *port){
	char *splitPorts = strtok((char *)port,"-");
	int i = 0;
	while(splitPorts != NULL){
		printf(" %s\n",splitPorts);
		portsArray[i] = atoi(splitPorts);
		splitPorts = strtok(NULL,"-");
		i++;
	}
}
//set the tcp_syn_retries to be user provided --retries =>max of 5?
void tcpConnect(TargetIp ip,char *port)
{
	int portsArray[2]; 
	ports(portsArray,port);
	socketConnection(ip,portsArray);
}
