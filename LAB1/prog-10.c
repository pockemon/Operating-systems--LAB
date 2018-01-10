//program to use chmod() system call
#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<unistd.h>

int main()
{
 int fd=open("file4.txt",O_RDWR|O_CREAT,S_IRWXU);
 
 if(fd==-1)
 { 
 perror("error");
 exit(1);
 }
 
 int fd1=chmod("file4.txt",S_IRWXU|S_IRWXG);
 
 if(fd1==-1)
 {
 perror("error");
 exit(1);
 } 
 printf("permissio of the file is changed to group\n");
 
 return 0;
}
