//first come first serve-arrival time of all process is different
/*
 Service Time : Service time means amount of time    after which a process can start execution. It is summation of burst time of previous processes (Processes that came before)
 1-Input the processes along with their burst time(bt)
   and arrival time(at)
 2-Find waiting time for all other processes i.e. for
   a given process  i:
       wt[i] = (bt[0] + bt[1] +...... bt[i-1]) - at[i]
 3-turn around time = waiting_time + burst_time for all processes
 4-Average waiting time=total_waiting_time / no_of_processes
 5-Average turn around time = total_turn_around_time / no_of_processes

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int n,i,j;
  printf("enter total number of process\n");
  scanf("%d",&n);
  int bt[n],ar[n];
  printf("enter arrival time and burst time for each process\n");
  for(i=0;i<n;i++)
  {
   scanf("%d %d",&ar[i],&bt[i]);
  }
  int wt[n],tat[n],ct[n];
  wt[0]=0;
  for(i=0;i<n;i++)
  {
    long int sum=0;
    for(j=i-1;j>=0;j--)
    {
     sum+=bt[j];
    }
    wt[i]=sum-ar[i];
    /*
      If waiting time for a process is in negative
      that means it is already in the ready queue
      before CPU becomes idle so its waiting time is 0
      */
    if(wt[i]<0)
      wt[i]=0;
  }
  for(i=0;i<n;i++)
  {
  tat[i]=wt[i]+bt[i];
  }
  for(i=0;i<n;i++)
  {
   ct[i]=tat[i]+ar[i];
   }
  long int waiting_total=0,turn_around_total=0;
  for(i=0;i<n;i++)
  {
   waiting_total+=wt[i];
   turn_around_total+=tat[i];
   }
   float avg_waiting_time=(float)waiting_total/(float)n;
   float avg_turn_around_time=(float)turn_around_total/(float)n;
   printf("Process\t\tBurst time\twaiting time\tTurn_around_time\tCompletion time\n");
   for(i=0;i<n;i++)
   {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i+1,bt[i],wt[i],tat[i],ct[i]);
    }
    printf("Average waiting time=%f\n",avg_waiting_time);
    printf("Average turn around time=%f\n",avg_turn_around_time);
    return 0;
}
