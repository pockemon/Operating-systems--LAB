//program to use open system call

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  
  int fd=open("file1.text",O_CREAT|O_RDWR,S_IRWXU);

  if(fd==-1)
  {
   perror("error");
   exit(1);
  }
  else
  printf("the assigned file descriptor to open is=%d\n",fd);
}
