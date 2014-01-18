#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


struct TreeNode{
	int key;
	struct TreeNode* parent;
	struct TreeNode* leftChild;
	struct TreeNode* rightChild;
};
struct BinTree{
	struct TreeNode* root;
};

typedef struct TreeNode Node;
typedef struct BinTree Tree;

void insert(int key,Tree* T){
	Node* x=T->root;
	Node* prev=NULL;
	Node* node=malloc(sizeof(Node));
	node->key=key;
	while(x!=NULL){
		if(x->key>node->key){
			prev=x;
			x=x->leftChild;
		}
		else{
			prev=x;
			x=x->rightChild;
		}
	}
	if(prev==NULL){
		T->root=node;
	}
	else if(prev->key<node->key){
		prev->rightChild=node;
		node->parent=prev;
	}
	else{
		prev->leftChild=node;
		node->parent=prev;
	}
}

Node* search(int key,Tree* T){
	Node* x=T->root;
	while(x!=NULL){
		if(x->key>key){
			x=x->leftChild;
		}
		else if(x->key<key){
			x=x->rightChild;
		}
		else{
			return x;
		}
	}
	return NULL;
}

Node* maximum(Node* x){
	while(x->rightChild!=NULL){
		x=x->rightChild;
	}
	return x;
}

Node* minimum(Node* x){
	while(x->leftChild!=NULL){
		x=x->leftChild;
	}
	return x;
}

void delete(Node* x,Tree* T){
	Node* temp;
	if(x==NULL) return;
	if(x->leftChild==NULL&&x->rightChild==NULL){
		if(x==T->root){
			T->root=NULL;
			free(x);
			return;
		}
		if(x->parent->leftChild==x){
			x->parent->leftChild=NULL;
			free(x);
		}
		else{
			x->parent->rightChild=NULL;
			free(x);
		}
	}
	else if(x->leftChild!=NULL&&x->rightChild!=NULL){
		temp=maximum(x->leftChild);
		x->key=temp->key;
		delete(temp,T);
	}

	else if(x->leftChild!=NULL||x->rightChild!=NULL){
		if(x->parent==NULL){
			if(x->leftChild==NULL)
			T->root=x->rightChild;
			else
			T->root=x->leftChild;
			free(x);
			return;
		}

		if(x->parent->leftChild==x){
			if(x->leftChild==NULL)
				x=x->rightChild;
			else
				x->parent->leftChild=x->leftChild;
			free(x);
		}
		else{
			if(x->leftChild==NULL)
				x->parent->rightChild=x->rightChild;
			else
				x->parent->rightChild=x->leftChild;
			free(x);
		}
	}
	}	

void inOrder(Node* N){
	if(N==NULL) return;
	inOrder(N->leftChild);
	printf("%d\t",N->key);
	inOrder(N->rightChild);
}
	
int main(){
	Tree* T=malloc(sizeof(Tree));
	int choice,key;
	Node *x;
	do{
		printf("Enter option:\n 1:insert\n 2:delete\n 3:exit \n");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter key\n");
			scanf("%d",&key);
			insert(key,T);		
		}
		else if(choice==2){
			printf("Enter key\n");
			scanf("%d",&key);
			x=search(key,T);
			delete(x,T);
		}
		else if(choice==3)
			break;
		else
			printf("Wrong option\n");
		inOrder(T->root);
		printf("\n");
	}while(1);
	return 0;
}
	
