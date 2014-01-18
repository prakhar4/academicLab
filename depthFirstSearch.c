#include<stdio.h>

int arr[100][100]={0,0};
int par[100];
int stime[100],time=0;
int ftime[100];
int flg[100]={0,0};

DFS(int st, int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		if((arr[st][j]==1) && (flg[j]!=1))
		{
			printf("\n %d ",j+1);
			flg[j]=1;
			par[j]=st+1;
			time++;
			stime[j]=time;
			DFS(j,n);
		}
		time++;
		ftime[j]=time;
	
	}

}

main()
{
	int ch=0, n, i, j, st;
	
	printf("\nEnter the number of nodes ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		while(ch!=99)
		{
			printf("\nEnter the adjacent node of %d ",i+1);
			scanf("%d",&ch);
			arr[i][ch-1]=1;
		}	
		ch=0;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");	
	}
	
	
	printf("\nEnter the starting node ");
	scanf("%d",&st);
	
	par[st-1]=-1;
	stime[st-1]=time;
	flg[st-1]=1;
	
	DFS(st-1,n);
	
	printf("\n parent");
	for(i=0;i<n;i++)
	{
		printf(" %d ",par[i]);	
	}
	
	printf("\n time");
	for(i=0;i<n;i++)
	{
		printf(" %d ",stime[i]);	
	}
	
	
	
	
	

}
