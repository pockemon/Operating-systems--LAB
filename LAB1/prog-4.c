#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<unistd.h>

int main()
{
  char buf[100];

  int fd=open("file1.txt",O_RDWR|O_RDONLY,S_IRWXU);
 
  if(fd==-1)
 { 
  perror("error");
  exit(1);
 }
  printf("file descriptor=%d\n",fd);
  
  int fd1=read(fd,&buf,15);
 
  if(fd1==-1)
  {
  perror("error");
  exit(1);
  }
  printf("file descriptor=%d\nstring=%s\n",fd1,buf);
  
 return 0;
}
