//program to use lseek() system call
#include<stdio.h>
#include<stdlib.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#include<unistd.h>

int main()
{

 int b;
 int a[10]={1,2,3,4,5,6,7,8,9.10};
 int fd=open("foo.txt",O_CREAT|O_RDWR|O_APPEND,0600);

 if(fd<0)
 {
 perror("open");
 exit(1);
 }

 //write something in file
 int fd1=write(fd,(void *)a,sizeof(a));
 
 if(fd1<0)
 {
 perror("write");
 close(fd1);
 exit(1);
 }

 //seek using lseek
 //suppose we want to access 4
 int fd2=lseek(fd,3+sizeof(int),SEEK_SET);
 
 if(fd2<0)
 {
 perror("lseek");
 close(fd2);
 exit(1);
 }

 //read from that position by lseek
 
 int fd3=read(fd,&b,sizeof(int));

 if(fd3<0)
 {
 perror("open");
 exit(1);
 }

 printf("b=%d\n",b);
 
 close(fd);

 return 0;
}



