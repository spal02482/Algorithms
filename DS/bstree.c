//Binary Search tree and their traversal
#include<stdio.h>
#include<stdlib.h>
typedef struct node{             //Constructing Node data structure
	struct node *left;
	int data;
	struct node *right;
}node;
typedef struct tree{            //Constructing Tree data structure
	node *root;
}tree;
void insertnode(tree *r)        //Function to add a node in a binary search tree
{
	int data;
	node *d;
	node *p=(node *)malloc(sizeof(node));   //Creating a Node
	printf("Enter the data:");
	scanf("%d",&data);
	p->left=NULL;
	p->data=data;
	p->right=NULL;
	node *q=r->root;			
	if(q==NULL)						//if the tree is empty assign the first node to root and return
	{
		r->root=p;
		return;
	}
	else
	{
		while(q!=NULL)
		{
			d=q;
			if(p->data<q->data)		//if the data isa 
			{
				q=q->left;
			}
			else{
				q=q->right;
			}
		}
		if(p->data<d->data)
			d->left=p;
		else
			d->right=p;
	}
}
void inordertraversal(node *root)
{
	if(root==NULL)
		return;
	inordertraversal(root->left);
	printf("%d\t",root->data);
	inordertraversal(root->right);
	return;
}
void reversetraversal(node *root)
{
	if(root==NULL)
		return;
	reversetraversal(root->right);
	printf("%d\t",root->data);
	reversetraversal(root->left);	
	return;
}
void deletetreenode(tree *r,int x)
{
	node *p,*rp,*prev=NULL;
	p=r->root;
	while(p!=NULL)
	{
		if(p->data==x)
			break;
		prev=p;
		if(x<p->data)
			p=p->left;
		else
			p=p->right;
	}
	if(p==NULL)
	{
		printf("Data not found\n");
		return;
	}
	if(p->left==NULL&&p->right==NULL)
		rp=NULL;
	else if(p->left==NULL)
		rp=p->right;
	else if(p->right==NULL)
		rp=p->left;
	else{
		node *f,*s;
		rp=p->right;
		s=rp->left;
		if(s==NULL)
			rp->left=p->left;
		else{
			while(s!=NULL)
			{
				f=rp;
				rp=s;
				s=s->left;
			}
			f->left=rp->right;
			rp->left=p->left;
			rp->right=p->right;
		}
	}
	if(prev==NULL)
	{
		r->root=rp;
		return;
	}
	else if(p==prev->left)
		prev->left=rp;
	else
		prev->right=rp;
	free(p);
}
/*Structure Double Pointer Returining Pointer
i.e. 1. typedef struct tree
	{
		node *root;
	}
	void insertnode (tree *r)
	{
		And accessing root pointer as r->root
	}
	in main()
	{
		tree r1;
		insertnode(&r1);
	}
     2. in main()
     	{
     		node *root
     		insertnode(&root);
     	}
     	and passing it as void insertnode(node **root)
     3. in main()
     	{
     		node *root
     		insertnode(root);
     	}
     	and passing it as node * insertnode(node *root)
     				{
     					.....
     					return root;
     					
     				}

*/
int main()
{
	int i,n;
	tree r1;
	r1.root=NULL;
	printf("Enter number of elements..\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		insertnode(&r1);
	printf("InorderTraversal:");
	inordertraversal((r1.root));
	printf("\nReverseTraversal:");
	reversetraversal(r1.root);
	printf("\nEnter the element to be deleted:");
	scanf("%d",&n);
	deletetreenode(&r1,n);
	printf("\nElements after deletions are:");
	inordertraversal(r1.root);
	printf("\n");
	return 0;
}




