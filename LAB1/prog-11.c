/*
 HARDIK RANA
 
 program to use system call getuid(),geteuid(),getgid(),getegid() & chown() system calls.
 
*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<unistd.h>

int main()
{
 int fd=open("file5.txt",O_RDWR|O_CREAT,S_IRWXU);
  
 if(fd==-1)
 {
 perror("error");
 exit(1);
 }
 
 uid_t uid=getuid();
 uid_t euid=geteuid();

 printf("uid=%d euid=%d\n",uid,euid );
  
 gid_t gid=getgid();
 gid_t egid=getegid();

 printf("gid=%d egid=%d\n",gid,egid ); 

 int fd1=chown("file5.txt",1001,0);

  if(fd1==-1)
 {
 perror("error");
 exit(1);
 }
 
 printf("changed the group and user id with fd1=%d\n",fd1);
}
