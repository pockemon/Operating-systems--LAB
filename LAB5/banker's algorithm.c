/*
   Hardik Rana
   
   Banker's Algorithm
   
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


int need[100][100],alloc[100][100],max[100][100],available[100];
bool finish[100];
int sequence[100];

/*
  Safety Algorithm:

  1) Let Work and Finish be vectors of length ‘m’ and ‘n’ respectively.
     Initialize: Work = Available
     Finish[i] = false; for i=1, 2, 3, 4….n

  2) Find an i such that both
     a) Finish[i] = false
     b) Needi <= Work if no such i exists goto step (4)

  3) Work = Work + Allocation
     Finish[i] = true
     goto step (2)

  4) if finish [i] = true for all i
     then the system is in a safe state otherwise unsafe state
*/

void issafe(int N,int M)
{
   int i,j,work[100],count=0;
   for(i=0;i<M;i++)
      work[i]=available[i];
   for(i=0;i<100;i++)
      finish[i]=false;
   while(count<N)
   {
      bool canAllot=false;
      for(i=0;i<N;i++)
      {

       if(finish[i]==false)
       {
         for(j=0;j<M;j++)
          {
          if(work[j]<need[i][j])
           {
              break;
            }
          }
          if(j==M)
         {
          for(j=0;j<M;j++)
           {
            work[j]+=alloc[i][j];
           }
          sequence[count++]=i;
          finish[i]=true;
          canAllot=true;
        }
       }

      }
      if(canAllot==false)
      {
        printf("System Is  not safe\n");
        return ;
      }
    }

    printf("System is in safe state\n");
    printf("Safe sequence :");
    for(i=0;i<N;i++)
        printf("%d ",sequence[i]);
    printf("\n");
}



int main()
{
    int n,m,i,j;

    printf("enter number of processes\n");
    scanf("%d",&n);

    printf("enter number of resources\n");
    scanf("%d",&m);

    printf("Enter the available resources :\n");
    for(i=0;i<m;i++)
       scanf("%d",&available[i]);

    printf("Enter the Allocation Matrix :\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
        {
          scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter the matrix for maximum demand of each process :\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
       {
        scanf("%d",&max[i][j]);
       }
    }
        //calculation of need matrix
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
       {
        need[i][j]=max[i][j]-alloc[i][j];
       }
    }

    //to check safe or not
    issafe(n,m);

    int indx,arr[100];
    printf("Enter the process no for resource request :");
    scanf("%d",&indx);

    printf("Enter the requested instances of Each :");
    for(i=0;i<m;i++)
        scanf("%d",&arr[i]);

    /*
       RESOURCE-REQUEST ALGORITHM

       1) If Requesti <= Needi
          Goto step (2) ; otherwise, raise an error condition, since the process has exceeded its maximum claim.

       2) If Requesti <= Available Goto step (3); otherwise, Pi must wait, since the resources are not available.

       3) Have the system pretend to have allocated the requested resources to process Pi by modifying the state as
          follows:
          Available = Available – Requesti
          Allocationi = Allocationi + Requesti
          Needi = Needi– Requesti

    */

    for(i=0;i<m;i++)
    {
     if(need[indx][i]<arr[i] || arr[i]>available[i] )
      {
         printf("Cannot request\n");
         break;
      }
    }

    if(i==m)
    {
      for(i=0;i<m;i++)
      {
         alloc[indx][i]+=arr[i];
         available[i]-=arr[i];
         need[indx][i]-=arr[i];
      }

    issafe(n,m);
    }
   return 0;
}
