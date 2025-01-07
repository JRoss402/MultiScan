#ifndef  ERROR_H
#define ERROR_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>

void socketErrors(const char* msg);
void connectErrors(const char* msg);
void listenErrors(const char* msg);
void bindErrors(const char* msg);
void testFoo(int num);

#endif

