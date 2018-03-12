#include<bits/stdc++.h>

using namespace std;

#define N 1000

typedef struct
{
    int pid;
    int size;
    bool allocated;
    int partition1;
}process;

typedef struct
{
    int size;
    int allocated;
    int pid;
}partition2;

int total_mem,n,m;
process p[N];
partition2 part[N];

int get_partition(int pid)
{
	for(int i=0; i<m; i++)
		if(part[i].pid == -1 && part[i].size >= p[pid].size)
			return i;

	return -1;
}

void free_partition(int pos)
{
	part[pos].pid = -1;
	part[pos].allocated = 0;
}

int external_fragment()
{
	int ret = 0;
	for(int i=0; i<m ;i++)
		if(part[i].pid == -1)
			ret += part[i].size;

	return ret;
}

int internal_fragment()
{
	int ret = 0;
	for(int i=0; i<m ;i++)
		ret += part[i].size - part[i].allocated;

	return ret;
}

int main()
{
  printf("enter total memory size\n");
  scanf("%d",&total_mem);

  printf("enter total number of partitions\n");
  scanf("%d",&m);
  printf("enter size for each partition\n");
  for(int i=0;i<m;i++)
  {
      scanf("%d",&part[i]);
      part[i].allocated=0; //initially not allocated
      part[i].pid = -1;  //initially pid of all processes is 0
  }

  printf("enter total number of processes\n");
  scanf("%d",&n);

  //allocating processes

  printf("enter size of each process\n");
  for(int i=0;i<n;i++)
  {
      scanf("%d",&p[i].size);
      p[i].pid = i;
      p[i].allocated = false;
      p[i].partition1 = -1;

      int pos = get_partition(i);
      if(pos == -1)
			continue;

      part[pos].allocated = p[i].size;
      part[pos].pid = i;
      p[i].allocated = true;
      p[i].partition1 = pos;
  }

    //for printing

    bool flag = 0;
	printf("\nProcess\t\tSize\t\tAllocated\tPartition\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t", i+1, p[i].size);
		if(p[i].allocated)
			printf("Yes\t\t");
		else
		{
			flag = 1;
			printf("No\t\t");
		}

		if(p[i].partition1 == -1)
			printf("None\n");
		else
			printf("%d\n", p[i].partition1 +1);
	}

	if(flag)
		printf("\nExternal Fragmentation : %d\n", external_fragment());

    //reallocation

    printf("\nenter new process size\n");
    scanf("%d",&p[n].size);
    p[n].pid = n;
    p[n].allocated = false;
	p[n].partition1 = -1;

	int pos = get_partition(n);
	if(pos==-1)
    {
        int r;
		printf("\nNo partition available\n");
		printf("Which process would you like to remove? ");

		scanf("%d", &r);
		r--;
		free_partition(p[r].partition1);

		pos = get_partition(n);
		if(pos == -1)
		{
			printf("\nStill not enough memory\n");
			printf("\nInternal Fragments : %d\n", internal_fragment());
			printf("External Fragments : %d\n\n", external_fragment());
			return 0;
		}
    }

    part[pos].allocated = p[n].size;
	part[pos].pid = n;
	p[n].allocated = true;
	p[n].partition1 = pos;

    //table
    printf("\n\nMemory Table\nPartition\tSize\t\tAllocated\tProcess\n");
	for(int i=0; i<m; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t", i+1, part[i].size, part[i].allocated);
		if(part[i].pid == -1)
			printf("None\n");
		else
			printf("%d\n", part[i].pid+1);
	}

	printf("\nInternal Fragments : %d\n\n", internal_fragment());
}
