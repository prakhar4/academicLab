#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
};
typedef struct tree node;

node *root=NULL, *temp=NULL, *ptr=NULL, *tem=NULL;

insert(int inf)
{
	ptr=(node*)malloc(sizeof(node));
	ptr->info=inf;
	ptr->left=NULL;
	ptr->right=NULL;
	
	if(root==NULL)
	{
		root=ptr;
		printf("\nroot assigned");
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			tem=temp;
			
			if(inf>(temp->info))
				temp=temp->right;
			else 
				temp=temp->left;
		}
		
		if(inf>(tem->info))
				{
					tem->right=ptr;
					printf("\nright assigned");
				}
		else 
				{
					tem->left=ptr;
					printf("\nleft assigned");
				}
	}

}

inorder(node *t)
{
	if(t!=NULL)
	{
	temp=t;
	inorder(t->left);
	printf(" %d ",t->info);
	inorder(t->right);
	}
}

delete(int in, node *p)
{
	while()

}



main()
{
	int ch=0,inf;
	node *temp;
	
	temp=root;
	printf("\n1.Insert\n2.See\n3.Exit\n4.Delete");
	
	while(1)
	{
		printf("\nEnter choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					printf("\nEnter the info ");
					scanf("%d",&inf);
					insert(inf);
					break;
			case 2:
					inorder(root);
					break;
			case 3:
					exit(0);
					break;
			case 4:
					printf("\nEnter the element to delete");
					scanf("%d",&inf);
					delete(inf, root);
					break;
					
			
			
		
		}
		
		

		
	}
	

}
