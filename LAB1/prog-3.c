/*
 HARDIK RANA
 
 program to use close() system call to close the file which was  opened by open() system call
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
 int fd=open("file1.txt",O_RDONLY|O_CREAT,S_IRUSR); 
  
 if(fd==-1)
 {
  perror("error");
  exit(1);
 }
 else
 {
  printf("opened the file with fd=%d\n",fd);
 }
  
 if(close(fd)==-1)
 {
 perror("error");
 exit(1);
 }
 printf("closed the file\n");
 return 0;
}
