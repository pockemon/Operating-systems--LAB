/*
 HARDIK RANA
 
 program to use system call creat() create  a new file.
 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  int fd=creat("file1.txt",S_IRWXU);
 
  if(fd==-1)
  {
   perror("error");
   exit(1);
  }
  else
  {
   printf("the assigned file descriptor to creat is=%d\n",fd);
  }
 return 0;
}
