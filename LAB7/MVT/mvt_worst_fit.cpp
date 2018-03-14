#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define N 1000
typedef struct
{
	int pid;
	int size;
	bool allocated;
}process;

typedef struct
{
	int pid; //-1 if free
	int size;
}slots;

process p[N];
slots s[N];
int mm_size, n, tot;

int external_fragment()
{
	int ret = 0;
	for(int i=0; i<tot; i++)
		if(s[i].pid == -1)
			ret += s[i].size;

	return ret;
}

void insert(int pos, int pid)
{
	for(int i=tot; i>pos; i--)
		s[i] = s[i-1];

	s[pos].pid = pid;
	s[pos].size = p[pid].size;
	p[pid].allocated = true;

	s[pos+1].size -= p[pid].size;
	tot++;
}

int get_slot(int pid)
{
	int pos=-1, maxi = -1e9;
	for(int i=0; i<tot; i++)
		if(s[i].pid == -1 && s[i].size >= p[pid].size && maxi < s[i].size)
		{
			pos = i;
			maxi = s[i].size;
		}

	return pos;
}

int free_slot(int pos)
{
	s[pos].pid=-1;

	if(pos!=tot-1 && s[pos+1].pid==-1)
	{
		s[pos].size += s[pos+1].size;
		for(int i=pos+1; i<tot-1; i++)
			s[i] = s[i+1];

		tot--;
	}

	if(pos>0 && s[pos-1].pid==-1)
	{
		s[pos-1].size += s[pos].size;
		for(int i=pos; i<tot-1; i++)
			s[i] = s[i+1];

		tot--;
	}
}

void print_memory_table()
{
	printf("\n\n====== Memory Table ==========\n");
	printf("Size\t|\tProcess\n");
	printf("============================== \n");
	for(int i=0; i<tot; i++)
	{
		printf("%d\t|\t", s[i].size);
		if(s[i].pid == -1)
			printf("None\n");
		else
			printf("%d\n", s[i].pid+1);
	}

	printf("============================== \n");
}

int main()
{
	//system("clear");
	int mm_size, n=0, ch;

	printf("Enter the total size of memory : ");
	scanf("%d", &mm_size);

	tot=1;
	s[0].pid = -1;
	s[0].size = mm_size;

	while(1)
    {
        printf("enter your choice\n");

		printf("1. Add new processs\n2.Remove existing process\n3.Exit\n");

		scanf("%d", &ch);

		if(ch == 1)
		{
			printf("\nEnter new process size : ");
			scanf("%d", &p[n].size);
			p[n].pid = n;
			p[n].allocated = false;

			int pos = get_slot(n);
			if(pos == -1)
				printf("\nNot enough contiguous memory to allocate memory to process\n");
			else if(s[pos].size == p[n].size)
			{
				p[n].allocated = true;
				s[pos].pid = n;
			}
			else
				insert(pos, n);

			print_memory_table();
			n++;
		}
		else if(ch == 2)
		{
			int prem;
			printf("\nWhich process would you like to remove? ");
			scanf("%d", &prem);
			prem--;

			for(int i=0; i<tot; i++)
				if(s[i].pid == prem)
					free_slot(i);

			print_memory_table();
		}
		else if(ch==3)
        {
            exit(1);
        }

	}
}
