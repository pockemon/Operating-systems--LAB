//sjf preemptive algorithm

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct process
{
    int pid; //process-id
    int bt; //burst time
    int rt; //remaining time
    int at; //arrival time
    int wt; //waiting time
    int tat; //turn-around-time
};

int main()
{
  int i,j,n,total_wt=0,total_tat=0;
  float avg_wt,avg_tat;
  printf("enter total number of processes\n");
  scanf("%d",&n);
  struct process proc[n],temp;
  printf("enter process-id,arrival-time and burst-time for each process\n");
  for(i=0;i<n;i++)
  {
      scanf("%d %d %d",&proc[i].pid,&proc[i].at,&proc[i].bt);
  }

  //to find waiting time for each process
  for(i=0;i<n;i++)
  {
      proc[i].rt=proc[i].bt;
  }

  int complete=0,t=0,min=INT_MAX;
  int shortest=0,f_time;
  bool check=false;

  //do this until all processes gets completed
  while(complete!=n)
  {
      //find minimum remaining time among the processes that arrives till the current time
      for(j=0;j<n;j++)
      {
        if((proc[j].at<=t) && (proc[j].rt<min) && proc[j].rt>0)
        {
            //printf("j=%d\n",j);
            //printf("proc[j].at=%d\n",proc[j].at);
            //printf("proc[j].rt=%d\n",proc[j].rt);
            min=proc[j].rt;
            shortest=j;
            check=true;
        }
      }

      if(check==false)
      {
          t++;
          continue;
      }

      //reduce remaining time of process which we find above
      proc[shortest].rt--;

      //update minimum
      min=proc[shortest].rt;
      if(min==0)
        min=INT_MAX;

      //if a process gets completely executed
      if(proc[shortest].rt==0)
      {
          //increment number of complete processes
          complete++;
         //find finish time of current process
         f_time=t+1;

         //calculate waiting time
         proc[shortest].wt=f_time-proc[shortest].at-proc[shortest].bt;

         if(proc[shortest].wt<0)
            proc[shortest].wt=0;
      }

       //increment time
       t++;
   }

   //finding turn-around-time
   for (i = 0; i < n; i++)
      proc[i].tat= proc[i].bt + proc[i].wt;

   for(i=0;i<n;i++)
   {
       total_wt+=proc[i].wt;
       total_tat+=proc[i].tat;
   }

   avg_wt=(float)total_wt/(float)n;
   avg_tat=(float)total_tat/(float)n;

   printf("process-id\tarrival-time\tburst-time\twaiting-time\tturn-around-time\n");
   for(i=0;i<n;i++)
   {
       printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].at,proc[i].bt,proc[i].wt,proc[i].tat);
   }

   printf("average waiting time=%f\n",avg_wt);
   printf("average turn around time=%f\n",avg_tat);

   return 0;
}



