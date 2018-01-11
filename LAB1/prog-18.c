//program to use chdir() system call
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#define path1 "/home/hardik/Desktop" 
int main()
{
  int fd=chdir(path1);
  
    if(fd<0)
        printf("Directory not changed\n");
    else
    {
     printf("Directory changed to Desktop\n");
    }
 }
