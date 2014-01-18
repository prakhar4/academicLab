#include<stdio.h>

int arr[100],flg=0;

bin_ser(int itm, int p,int q)
{
	if(p<=q)
	{
	int mid	;
	mid=(p+q)/2;
	
	if(itm==arr[mid])
	{
		printf("\nElement found at %d position",mid+1);
		flg=1;
		return (0);
	}
	else
	{
	bin_ser(itm,p,mid-1);
	bin_ser(itm,mid+1,q);
	}
	}
	
	
}



main()
{
	int n,i,item;

	printf("Enter the limit");
	scanf("%d",&n);
	printf("Enter sorted array");
	
	for(i=0;i<n;i++)
	  scanf("%d",&arr[i]);
	  
	 printf("Enter the item to be searched");
	 scanf("%d",&item);
	  
	bin_ser(item,0,n-1);
	
	if(flg==0)
	  printf("\nElement not found");


}


