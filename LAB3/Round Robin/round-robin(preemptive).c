//Hardik Rana

/*
  round robin algorithm with same arrival time.
  because of same arrival time turn around time and completion time of processes will be same
  an array rem_bt[] will keep track of remaining burst time of processes.we will initialize it as a copy of bt[] array
  wt[] array will store waiting time of all processes.initializes as 0.
  initial time=0
  we will keep traverse processes as all processes are not complete and do this process
  1] if rem_bt[i]>quantum
     <i>t=t+quantum
     <ii>bt[i]-=quantam
  2] else
    <i>t=t+bt_rem[i]
    <ii>wt[i]=t-bt[i]
    <iii>bt_rem[i]=0 //process is done.
*/

#include<stdio.h>
#include<stdbool.h>

struct process
{
   int id;
   int bt;
   //int at;
   int wt;
   int tat;
   int rem_bt;
   //int flag;
};

int main()
{
    int n,i;
    printf("enter total number of processes\n");
    scanf("%d",&n);
    struct process proc[n];
    printf("\nenter process-id and burst-time for each process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&proc[i].id,&proc[i].bt);
    }
    printf("\nenter time quantum\n");
    int t1;
    scanf("%d",&t1);

    int total_wt=0,total_tat=0;

    //for finding waiting time for each process
    for(i=0;i<n;i++)
    {
        proc[i].rem_bt=proc[i].bt;
    }

    int t=0; //current time

    //keep traversing until all processes are done
    while(1)
    {
        bool done=true;

        //traverse all process one by one
        for(i=0;i<n;i++)
        {
          if(proc[i].rem_bt>0)
          {
          done=false;

          if(proc[i].rem_bt>t1)
          {
              t+=t1;
              proc[i].rem_bt-=t1;
          }

          else
          {
           t=t+proc[i].rem_bt;
           proc[i].wt=t-proc[i].bt;
           proc[i].rem_bt=0;
          }
          }
        }
         if(done==true)//all processes are done
            break;
      }

     //finding turn around time
     for(i=0;i<n;i++)
     {
         proc[i].tat=proc[i].bt+proc[i].wt;
     }

     printf("process-id\tburst-time\twaiting-time\tturn-around-time\n");
     for(i=0;i<n;i++)
     {
         printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i].id,proc[i].bt,proc[i].wt,proc[i].tat);
     }

}

