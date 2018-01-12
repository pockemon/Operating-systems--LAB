/*
 HARDIK RANA
 
 program to use system call signal().
 
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);
    exit(1);
}

int main()
{
 signal(SIGINT,handle_sigint);
 while(1)
 {
   printf("Hello world i'm going to sleep for a second\n");
   sleep(1);
 }
 return 0;
}
