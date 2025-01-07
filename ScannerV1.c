#include "tcpconnect.h"
#include "utils."


int main(int argc, char* argv[]){
	int count = 0;
	int option_index = 0;
	struct option long_options[] ={
	{"help",no_argument,0,'h'},
	{"learn",no_argument,0,'l'},
	{"tcp",no_argument,0,'t'},
	{"syn",no_argument,0,'s'},
	{"custom",no_argument,0,'c'},
	{"udp",no_argument,0,'u'},
	}
if(argc <=2){
	PrintUsage();
	exit(EXIT_SUCCES);
}

while((count = getopt_long(argc, arv, "ht:r:",long_options,&option_index)) != -!){
	switch(count){
		case 'h':
		PrintUsage();
		exit(EXIT_SUCCESS);
		break;
		case 't':
		tcpconnect();
	}
}

}
