#include<stdio.h>

int wgt[100][100]={0,0};
int par[100];
int dis[100];
int flg[100];

initialise(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		dis[i]=9999;
		flg[i]=0;
		par[i]=-1;	
	}
}

relax(int u, int v, int w)
{
	if(dis[v]>dis[u]+w)
	{
		printf("\nrelax for %d %d ",u,v);	
		dis[v]=dis[u]+w;
		par[v]=u+1;
	}
}


int ext_small(int n)
{
	int i,sm=dis[0],j=0;
 	for(i=0;i<n;i++)
 	{
 		//if(i==) continue
 		if((dis[i]<=	sm) && (flg[i]!=1))
 		{
 			sm=dis[i];
 			j=i;
 			printf("\nyes1 %d ",j);
 		}
 	}
 	flg[j]=1;
 	printf("\n flag %d ",flg[j]);
 	return (j);

}

djikstra(int st, int n)
{
	int sm,i,j;
	
	initialise(n);
	dis[st-1]=0;
	
	
	for(i=0;i<n;i++)
	{
		sm=ext_small(n);
		printf("\nWorking %d ",sm);
		printf(" %d ",sm+1);
		
		for(j=0;j<n;j++)
		{
			if((j==sm) || (wgt[sm][j]==0)) continue;
			else
			relax(sm,j,wgt[sm][j]);
		}
	}
}




main()
{
	int n,i,j,ch=0,wei,st;
	
	printf("\nEnter the number of nodes");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		while(ch!=99)
		{
			printf("\nEnter the adjacent node of %d ",i+1);
			scanf("%d",&ch);
			if(ch!=99)
			{
				printf("\nEnter the positive weight of this edge ");
				scanf("%d",&wei);
				wgt[i][ch-1]=wei;
			}
		}
		ch=0;
	}
	
	printf("\nEnter the start node");
	scanf("%d",&st);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",wgt[i][j]);
		}
		printf("\n");
	}
	
	djikstra(st,n);
	
	printf("\nThe parents are ");
	for(i=0;i<n;i++)
		printf(" %d ",par[i]);
		
	printf("\nThe distance are ");
	for(i=0;i<n;i++)
		printf(" %d ",dis[i]);
	
	


}
