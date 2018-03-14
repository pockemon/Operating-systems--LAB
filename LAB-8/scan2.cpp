#include<bits/stdc++.h>

int find(int d[],int n,int disk)
{
for(int i=0;i<n-1;i++)
  {
    if(d[i]>disk)
    {
      return i;
      break;
    }
  } 
}

int main()
{
 int i,j,n;
 int disk;   //loc of head
 int temp,max;     
 int dloc;   //loc of disk in array

 printf("enter number of location\n");
 scanf("%d",&n);
 
 int d[n+1]; //disk queue

 printf("enter position of head\n");
 scanf("%d",&disk);
 
 printf("enter elements of disk queue\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&d[i]);
 }
 
 //d[n]=disk;

 //printf("d[%d]=%d\n",n,disk);

 //n=n+1;

 //printf("n=%d\n",n);

 for(i=0;i<n-1;i++)    // sorting disk locations
 {
  for(j=i+1;j<n;j++)
  {
    if(d[i]>d[j])
    {
    temp=d[i];
    d[i]=d[j];
    d[j]=temp;
    }
  }
 }

 printf("elements after sorting\n");

 for(i=0;i<n;i++)
 {
 printf("%d ",d[i]);
 }

 printf("enter your choice\n1.left\n2.Right\n");

 int c;
 int sum=0;
 scanf("%d",&c);

//go towards left
 if(c==1)
 {
  int previous = find(d,n,disk);
  //for(i=0;i<n-1;i++)
  //{
    //if(d[i]>disk)
    //  break;
  //}
   previous = previous-1;
   printf("%d\n",previous);

   sum+=abs(disk-d[previous]);

   printf("%d->",disk);

   for(i=previous;i>=0;i--)
   {
    printf("%d ->",d[i]);
    if(i!=0)
       sum+=abs(d[i]-d[i-1]);
    else if(i==0)
       sum+=d[i];
   }

   printf("0 ->");

   sum+=d[previous+1];

   for(i=previous+1;i<n;i++)
   {
    printf("%d ->",d[i]);

    if(i!=n-1)
       sum+=abs(d[i+1]-d[i]);
   }

   printf("\nmovement of total cylinders %d\n",sum);
 }

 //go towards right
else if(c==2)
{
  int previous = find(d,n,disk);
  //for(i=0;i<n-1;i++)
  //{
    //if(d[i]>disk)
    //  break;
  //}
   //previous = previous-1;
   printf("%d\n",previous);

   sum+=abs(d[previous]-disk);

   printf("%d->",disk);

   for(i=previous;i<n;i++)
   {
    printf("%d ->",d[i]);
    if(i!=n-1)
       sum+=abs(d[i+1]-d[i]);
    //else if(i==n-1)
       //sum+=d[i];
   }
   sum+=abs(d[n-1]-d[previous-1]);

   for(i=previous-1;i>=0;i--)
   {
     printf("%d ->",d[i]);
     if(i!=0)
      sum+=abs(d[i]-d[i-1]);
   }
   //printf("0 ->");

   printf("\nmovement of total cylinders %d\n",sum);
}

return 0;
}