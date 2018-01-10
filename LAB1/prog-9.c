//program to use access() system call
#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<unistd.h>

int main()
{
 int fd=open("file2.txt",O_RDWR,S_IRWXU);
 
 if(fd==-1)
 {
 perror("error"); 
 exit(1);
 }
 printf("fd=%d\n",fd);
 
 int fd1=access("file2.txt",F_OK);

 if(fd1==0)
 printf("user has file access permisiion\n");
 
 int fd2=access("file2.txt",R_OK);

 if(fd2==0)
 printf("user has read permisiion\n");
 
 int fd3=access("file2.txt",W_OK);
 
 if(fd3==0)
 printf("user has write permisiion\n");
 
 
 int fd4=access("file2.txt",X_OK);

 if(fd4==0)
 printf("user has execuete permisiion\n");
 
 return 0;
}
