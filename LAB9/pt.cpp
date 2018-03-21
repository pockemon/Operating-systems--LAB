#include<bits/stdc++.h>
using namespace std;

int main()
{
	/*
	 las-logical address space
	 np=number of processes
	 ps=process-size
	 pas=physical address spce
	 nf=number of frames 
	 la=logical address
	 pa=physical address
	 */
	int las,np,j,ps,pas,nf,i,la,pa;
	int choice=1;
	printf("enter total logical address space\n");
	scanf("%d",&las);

	printf("enter page-size\n");
	scanf("%d",&ps);

	np=las/ps;   //number of pages

	printf("enter physical address space\n");
    scanf("%d",&pas);

    nf=pas/ps;   //no.of frames-coz page size and frmae size are same

    int page_table[np],count=0;

    printf("enter page table(allocated frame numbers)\n");

    for(i=0;i<np;i++)
    {
       int flag=0;
       printf("Page %d (Enter -1 for NULL) -\n", i);
	   scanf("%d", &page_table[i]);
	   count++;
	   int temp=page_table[i];
	   if(count>1)
	   {
	   for(j=0;j<count-1;j++)
	   {
	   	if(temp==page_table[j] && page_table[j]!=-1)
	   	{
	   		printf("enter another frame,this frame is already allocated\n");
	   		/*
	   		printf("Page %d (Enter -1 for NULL) - \n", i+1);
	        scanf("%d", &page_table[i]);
	        */
	        flag=1;
	        break;
	   	}
	   }
	   }
	   if(flag==1)
	   {
	   	printf("Page %d (Enter -1 for NULL) - \n", i);
	    scanf("%d", &page_table[i]);
	   }
    }

    while(choice==1)
    {
    	printf("enter logical address\n");
    	scanf("%d",&la);

    	if(la>=las)
    	{
    		printf("logical address is out of bound\n");
    	}

    	else
    	{
         if(page_table[la/ps]==-1)
    	{
    		printf("page yet not allocated\n");
    	}

    	else
    	{
           pa = (page_table[la/ps]*ps)+(la%ps);
           printf("corresponding physical address is=%d\n",pa);
    	}
        /*
    	printf("Do you want to enter more? (yes=1/no=0): ");
		scanf("%d", &choice);
		*/
	    }
	    printf("Do you want to enter more? (yes=1/no=0): ");
		scanf("%d", &choice);
    }


}