/*
    Rana Hardik
    
    sjf non-preemptive with same arrival time
*/

#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tat;
};

int main()
{
  int i,j,n,total_wt=0,total_tat=0;
  float avg_wt,avg_tat;
  printf("enter total number of processes\n");
  scanf("%d",&n);
  struct process proc[n],temp;
  printf("enter process-id and burst-time for each process\n");
  for(i=0;i<n;i++)
  {
      scanf("%d %d",&proc[i].pid,&proc[i].bt);
  }

  //sort according to burst time
  for(i=0;i<n-1;i++)
  {
      for(j=i+1;j<n;j++)
      {
          if(proc[i].bt>proc[j].bt)
          {
            temp=proc[i];
            proc[i]=proc[j];
            proc[j]=temp;
          }
      }
  }
  printf("processes after sorting according to burst time\n");
  printf("process-id\tburst-time\n");
  for(i=0;i<n;i++)
  {
      printf("%d\t\t%d\n",proc[i].pid,proc[i].bt);
  }

  //for finding waiting time for each process
  proc[0].wt=0;
  total_wt=proc[0].wt;
  for(i=1;i<n;i++)
  {
      proc[i].wt=proc[i-1].wt+proc[i-1].bt;
      //printf("%d\n",proc[i].wt);
      total_wt+=proc[i].wt;
      //printf("%d\n",total_wt);
  }

  //for finding turn around time for each process
  for(i=0;i<n;i++)
  {
      proc[i].tat=proc[i].wt+proc[i].bt;
      //printf("%d\n",proc[i].tat);
      total_tat+=proc[i].tat;
       //printf("%d\n",total_tat);
  }
  //printf("%d\n",total_wt);
  //printf("%d\n",total_tat);
  avg_wt=(float)total_wt/(float)n;
  avg_tat=(float)total_tat/(float)n;

  printf("process-id\tburst-time\twaiting-time\tturn-around-time\n");
  for(i=0;i<n;i++)
  {
      printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].bt,proc[i].wt,proc[i].tat);
  }

  printf("average waiting time=%f\n",avg_wt);
  printf("average turn-around-time=%f\n",avg_tat);

  return 0;
}

