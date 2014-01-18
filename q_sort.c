#include<stdio.h>

int arr[100];

int arrange(int p, int q)
{
	int x,i=p-1,j,tem;
	x=arr[q];
	
	for(j=p;j<q;j++)
	 {
	  if(arr[j]<arr[q])
	  {
	  	i++;
	  	tem=arr[i];
	  	arr[i]=arr[j];
	  	arr[j]=tem;
	  }
	 }
	
	i++;
	tem=arr[i];
	arr[i]=arr[q];
	arr[q]=tem;
	return (i);
}


qsort(int p, int q)
{
	int r;
	if(p<q)
	{
		r=arrange(p,q);
		qsort(p,r-1);
		qsort(r+1,q);	
	}
}




main()
{
	int n,i;

	printf("Enter the limit");
	scanf("%d",&n);
	
	printf("Enter the elements");
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	qsort(0,n-1);
	printf("\n\n");
	
	for(i=0;i<n;i++)
	printf(" %d ",arr[i]);
		
	

}
