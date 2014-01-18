#include<stdio.h>

int arr[100][100];
int tem[100][100];
int count=0;

f_marshal(int n)
{
	int i,j,k;
	
	for(k=0;k<n;k++)
	{
	if(count!=0)
	  {
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			arr[i][j]=tem[i][j];
		}
	  }
	for(i=0;i<n;i++)
	  {
		count++;
		for(j=0;j<n;j++)
		{
			if(arr[i][j]<(arr[i][k]+arr[k][j]))			
			  tem[i][j]=arr[i][j];
			else
			  tem[i][j]=(arr[i][k]+arr[k][j]);
		
		}
	
	  }
	  see(n);
	
	}
	
}

see(int n)
{
	
	printf("\n\n");
	int i,j;
	for(i=0;i<n;i++)
	    {
		
		  for(j=0;j<n;j++)
			  printf(" %d ",tem[i][j]);
		  printf("\n");
		}

}

main()
{
	int i,j,n,ch=0,wei,st;
	
	printf("\nEnter the number of nodes  ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			
			printf("\nEnter the %d and %d weight ",i+1,j+1);
			scanf("%d",&arr[i][j]);
		
		}
		
		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");	
	}
	
	f_marshal(n);
	
}


