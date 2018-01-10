//program to use write() system call
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<unistd.h>

int main()
{
 int fd;
 char buf[100];
 fd=open("file2.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
   
 if(fd==-1)
 {
 perror("error");
 exit(1);
 }
 
 int fd2=write(fd,"Hello hardik\n",strlen("Hello hardik\n"));
 
  printf("called write(% d, \"hello geeks\\n\", %d)."
    " It returned %d\n", fd, strlen("hello geeks\n"), fd2);

 int fd3=write(fd,"again hello\n",strlen("again hello"));
 
 int fd4=read(fd,&buf,10); 

 printf("string=%s\n",buf);
 
  return 0;

}
