#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j;
    printf("enter total number of pages\n");
    scanf("%d",&n);

    int ref_str[n];
    printf("enter reference string of pages\n");
    for(i=0;i<n;i++)
    {
     scanf("%d",&ref_str[i]);
    }

    int frames;
    printf("enter Total Number of Frames:\n");
    {
        scanf("%d", &frames);
    }

    int a[frames],pf=0;  //pf ..page faults
    for(i=0;i<frames;i++)
    {
        a[i]=-1;
    }
    printf("allocation of frames to process is as following\n");

    printf("ref_string\t\tpage_frames\n");

    for(i=0;i<n;i++)
    {

        int s=0;
        for(j=0;j<frames;j++)
        {
            if(ref_str[i]==a[j])
            {
                s++;
                pf--;  //page hit
            }
        }

        pf++;

        if((pf<=frames) && (s==0))
        {
            a[i]=ref_str[i];
        }
        else if(s==0)
        {
            a[(pf-1)%frames] = ref_str[i];
        }
         printf("\n");
         printf("%d\t\t",ref_str[i]);
         for(int k= 0;k<frames;k++)
         {
            printf("%d\t", a[k]);
         }

    }

      printf("\nTotal Page Faults=%d\n", pf);

      printf("total page hit is=%d\n",n-pf);

      return 0;
}
