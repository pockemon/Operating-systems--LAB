/*
 HARDIK RANA
 
 program to use system call getpid() & getppid()
 
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("Parent process id = %d\n",pid );
    printf("Child process with parent id = %d\n",ppid );

    return 0;
}
