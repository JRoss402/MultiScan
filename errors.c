#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include <unistd.h>



void socketErrors(const char* msg){
	switch(errno){
		case EINVAL:
			printf("Error: Invalid Argument.");
			break;
		case EMFILE:
			printf("Error: Too many open files.");
			break;
		case ENFILE:
			printf("Error: System-wide file table overflow.");
			break;
		case EAFNOSUPPORT:
			printf("Error: Address family not supported.");
			break;
		case EPROTONOSUPPORT:
			printf("Error: Protocal not supported.");
			break;
		case ENOMEM:
			printf("Error: Out of memory.");
			break;
		case EADDRINUSE:
			printf("Error: Address already in use.");
			break;
		case EACCES:
			printf("Error: Permission denied.");
			break;
		case EFAULT:
			printf("Bad address.");
		default:
			printf("Error: Unknown Error");
			break;
	}
}

void testFoo(int num){
	switch(num){
		case 3:
			printf("Test worked");
			break;
	}
}
