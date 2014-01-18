#include<stdio.h>

int gph[100][100];
int dis[100],par[100];
int wgt[100][100];

initialise(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		dis[i]=9999;
		par[i]=-1;
	}
}

relax(int u, int v, int w)
{
	if(dis[v]>(dis[u]+w))
	{
		dis[v]=dis[u]+w;
		par[v]=u+1;
	}
}

bellman(int st,int n)
{
	initialise(n);
	dis[st-1]=0;
	
	int i,l,m,o;
	for(i=0;i<n;i++)
	{
		for(l=0;l<n;l++)
		{
			for(m=0;m<n;m++)
			{
				if(wgt[l][m]==0) continue;
				else
					{
						relax(l,m,wgt[l][m]);
					}
				
			}
			
		
		}
	
	}

}





main()
{
	int i,j,n,ch=0,wei,st;
	
	printf("\nEnter the number of nodes  ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		while(ch!=99)
		{
			printf("\nEnter the neighbour of %d ",i+1);
			scanf("%d",&ch);
			if(ch!=99)
			{
			  printf("\nEnter the weight of this edge ");
		 	  scanf("%d",&wei);
			}
			wgt[i][ch-1]=wei;
		}
		ch=0;
	}
	
	printf("\nEnter the starting point ");
	scanf("%d",&st);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",wgt[i][j]);
		}		
		printf("\n");	
	}
	
	bellman(st,n);
	
	printf("\nParents ");
	for(i=0;i<n;i++)
	  printf("%d ",par[i]);
	  
	printf("\nDistances ");
	for(i=0;i<n;i++)
	  printf("%d ",dis[i]);
	


}
