#include<stdio.h>
#include<stdlib.h>

int a[100][100]={0,0};
int que[100],front=0,rear=-1;
int par[100];
int chk[100];
int time[100],tim=0;

enque(int inf)
{
	rear++;
	que[rear]=inf;
}

int deque()
{
	int inf;
	inf=que[front];
	front++;
	return (inf);	
	
}

intialise(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	 par[i]=0;
     time[i]=0;
     chk[i]=0;;
    }
}

BFS(int st, int n)
{
	 int p,q,r,i,j;
	 intialise(n);

	 enque(st-1);
	 time[st-1]=0;
	 par[st-1]=-1;
	 chk[st-1]=1;
	 
	 while(front<=rear)
	 {
	 	printf("\nworking");
	 	p=deque();
	 	printf(" %d ",p+1);
	 	//tim++;
	 	for(i=0;i<n;i++)
	 	{
	 		if(a[p][i]==1 && chk[i]==0)
	 		{
	 			enque(i);
	 			par[i]=p+1;
	 			time[i]=time[p]+1;
	 			chk[i]=1;
	 		}
	 	}	
	 }
}


void see(int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("\n%d",par[i]);
	}

	for(i=0;i<n;i++)
	{
		printf("\n\t%d",time[i]);
	}

}



main()
{
	int i,j,n,ch=0,st;

	printf("Enter the no of nodes");
	scanf("%d",&n);
	//printf("\nEnter the relation of nodes  ");
	
	for(i=0;i<n;i++)
	{
		while(ch!=-1)
		{
			printf("\nEnter the adjacent nodes of %d  ",i+1);
			scanf("%d",&ch);
			a[i][ch-1]=1;
		
		}
		
		ch=0;
		
	}
	
	printf("\n\nThe relation matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter the starting node ");
	scanf("%d",&st);
	
	BFS(st,n);
	
	see(n);
	

}

