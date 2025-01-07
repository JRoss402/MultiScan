#ifndef TCPCONNECT_H
#define TCPCONNECT_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>

typedef const char* TargetIp;
typedef struct sockaddr_in TargetAddrIPv4;

int addressValidation(TargetIp ip,TargetAddrIPv4 *targetAddr);
int socketCreation();
int socketConnection(TargetIp ip,int *portsArray);

void timeoutHandler(int ignored);
void setSocketFDs(int socketFD);
void setSocketNonBlocking(int socketFD);
void tcpConnect(TargetIp ip,char *port);
#endif

