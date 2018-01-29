//HARDIK RANA

/*
first come first serve-1[Arrival time of all process is same 0]
1.first process that comes need not to wait so waiting time for process 1 will be 0 i.e. wt[0] = 0.
2.Find waiting time for all other processes i.e. for process i ->  wt[i] = bt[i-1] + wt[i-1] .
3-turnaround time = waiting_time + burst_time  for all processes.
4-average waiting time = total_waiting_time / no_of_processes.
5-turnaround time= total_turn_around_time / no_of_processes.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int n,i;
  printf("enter total number of process\n");
  scanf("%d",&n);
  int bt[n];
  printf("enter burst time for each process\n");
  for(i=0;i<n;i++)
  {
   scanf("%d",&bt[i]);
  }
  int wt[n],tat[n];
  wt[0]=0;
  for(i=0;i<n;i++)
  {
   wt[i]=bt[i-1]+wt[i-1];
  }
  for(i=0;i<n;i++)
  {
  tat[i]=wt[i]+bt[i];
  }
  long int waiting_total=0,turn_around_total=0;
  for(i=0;i<n;i++)
  {
   waiting_total+=wt[i];
   turn_around_total+=tat[i];
   }
   float avg_waiting_time=(float)waiting_total/(float)n;
   float avg_turn_around_time=(float)turn_around_total/(float)n;
   printf("Process\t\tBurst time\twaiting time\tTurn_around_time\n");
   for(i=0;i<n;i++)
   {
    printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time=%f\n",avg_waiting_time);
    printf("Average turn around time=%f\n",avg_turn_around_time);
    return 0;
    }
