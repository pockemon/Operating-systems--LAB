/*
   Rana Hardik
   
   Shortest Job First-nonpreemptive algorithm with different arrival time
   
*/

#include<stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int flag;
};

int main()
{
    int n;
    //int ct[n],wt[n],tat[n];
    printf("enter total number of processes\n");
    scanf("%d",&n);
    struct process proc[n],temp;
    int i,j;
    //int ct[n+1],wt[n+1],tat[n+1],flag1[n+1],flag2[n+1];
    //flag1[n+1];
    for(i=0;i<n;i++)
    {
        proc[i].flag=0;
    }
    printf("\nenter process-id,arrival-time and burst-time for each process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&proc[i].pid,&proc[i].at,&proc[i].bt);
    }
    
    printf("before sorting according to arrival-time\n");
    printf("process-id\tarrival-time\tburst-time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].at,proc[i].bt);
    }
    //sorting according to arrival time
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(proc[i].at>proc[j].at)
            {
                temp=proc[i];
                proc[i]=proc[j];
                proc[j]=temp;
            }
        }
    }
    printf("after sorting according to arrival-time\n");
    printf("process-id\tarrival-time\tburst-time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].at,proc[i].bt);
    }
    
    int r=proc[0].at;
    //printf("r=%d\n",r);
    int p=1;
    int k=0;
    int min=proc[0].bt;
    //printf("min=%d\n",min);
    while(proc[p].at==r && p<=n)
    {
      //printf("proc[%d].at=%d\n",p,proc[p].at);
      if(proc[p].bt<min)
        {
        //     printf("proc[%d].bt=%d\n",p,proc[p].bt);
             min=proc[p].bt;
          //   printf("min=%d\n",min);
             k=p;
            // printf("k=%d\n",p);
        }
      p++;
    }

    proc[k].ct=proc[k].at+proc[k].bt;
    //printf("proc[%d].ct=%d\n",k,proc[k].ct);
    proc[k].flag=1;
    int l=k;
    int d=proc[k].ct;
    //printf("d=%d\n",d);
    //int min1=1000;
    int counter=1;
    while(counter!=n)
    {
    int min1=1000;
    for(i=0;i<n;i++)
    {
        if(proc[i].flag==0 && proc[i].at<=d)
        {
            //printf("proc[%d].at=%d,proc[%d].flag=%d\n",i,proc[i].at,i,proc[i].flag);
            //printf("proc[%d].bt=%d\n",i,proc[i].bt);
            //printf("min1=%d\n",min1);
            if(proc[i].bt<min1)
            {
                min1=proc[i].bt;
                //printf("min1=%d\n",min1);
                k=i;
                //printf("k=%d\n",k);
            }
        }
    }
    proc[k].ct=proc[l].ct+min1;
    //printf("proc[%d].ct=%d\n",l,proc[l].ct);
    //printf("min1=%d\n",min1);
    //printf("proc[%d].ct=%d\n",k,proc[k].ct);
    proc[k].flag=1;
    d=proc[k].ct;
    //printf("d=%d\n",d);
    counter++;
    l=k;
    //printf("counter=%d\n",counter);
    }

    int tat1=0,wt1=0;
    for(i=0;i<n;i++)
    {
        proc[i].tat=proc[i].ct-proc[i].at;
        //printf("tat[%d]=%d\n",i,proc[i].tat);
        tat1+=proc[i].tat;
    }

    //printf("waiting-time\n");
    for(i=0;i<n;i++)
    {
        proc[i].wt=proc[i].tat-proc[i].bt;
       // printf("wt[%d]=%d\n",i,proc[i].wt);
       wt1+=proc[i].wt;
    }

    printf("process-id\tarrival-time\tburst-time\tcompletion-time\twaiting-time\tturn-around-time\n");
    for(i=0;i<n;i++)
    {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].at,proc[i].bt,proc[i].ct,proc[i].wt,proc[i].tat);
    }

    //printf("wt1=%d\n",wt1);
    //printf("tat1=%d\n",tat1);
    float tat2,wt2;
    tat2=(float)tat1/(float)n;
    wt2=(float)wt1/(float)n;
    printf("\naverage turn-around-time=%f\n",tat2);
    printf("\naverage waiting-time=%f\n",wt2);

    return 0;
}
