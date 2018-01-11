//program to use kill() system call
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 int i;
 pid_t ch=fork();
 printf("ch=%d\n",ch);
 int flag=0;
 for(i=0;i<1000;i++)
 {
  if(i==100)
      kill(6758,SIGKILL);
  printf("%d\n",i);
 }
}
