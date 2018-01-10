/*
 HARDIK RANA
 
 program to use system call link().
 
*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<unistd.h>

int main()
{
 int fd=link("file2.txt","file3.txt"); 

 if(fd==-1)
 {
 perror("link");
 exit(1);
 }
 
 unlink("file3.txt");
  
}

