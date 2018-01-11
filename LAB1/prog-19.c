//program to use alarm() system call

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int flag=3;

void handle(int sig)
{ 
 printf("hello\n");
 flag--;
 alarm(2);
}

int main()
{
 signal(SIGALRM,handle);
 alarm(2);
 while(flag);
 {
 
 }
 printf("done\n");
 return 0;
}
