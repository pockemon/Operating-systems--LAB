#include<bits/stdc++.h>
using namespace std;

int main()
{

    int head;
    printf("enter head position\n");
    cin>>head;

    int n,i;
    cout<<"enter total requets"<<endl;
    cin>>n;
    int queue1[n],done[n];
    printf("enter requests\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&queue1[i]);
        done[i]=0;
    }

    printf("%d->",head);

    int temp1=head;
    int count1=0,j,sum=0;
    while(count1!=n)
    {
    int temp=100000;
    int k=-1;
    for(j=0;j<n;j++)
    {
        if(temp1!=queue1[j] && done[j]==0)
        {
        if(temp>abs(temp1-queue1[j]))
        {
           temp = abs(temp1-queue1[j]);
           k = j;
        }
        }
    }
    sum+=temp;
    printf("%d->",queue1[k]);
    count1++;
    temp1=queue1[k];
    done[k]=1;
    //cout<<temp1<<endl;
    }
    cout<<endl;
    cout<<"total head movement is="<<sum<<endl;


}
