#include<stdio.h>
#include<malloc.h>
struct bst
{
       int data;
       struct bst *left,*right;
};
void inorder(struct bst *h)
{
     if(!h)
     return;
     inorder(h->left);
     printf("%4d",h->data);
     inorder(h->right);
}
struct bst *maximum(struct bst *r)
{
	if(r==NULL)
	return r;
	while(r->right!=NULL)
	r=r->right;
	return r;
}
struct bst *minimum(struct bst *r)
{
	if(r==NULL)
	return r;
	while(r->left!=NULL)
	r=r->left;
	return r;
}

void insert(struct bst **h,int x)
{
     if((*h)==NULL)
     {
                   struct bst *r;
                   r=(struct bst *)malloc(sizeof(struct bst));
                   r->data=x;
                   r->left=NULL;
                   r->right=NULL;
                   *h=r;
                   return;
     }
      if((*h)->data>x)
        insert(&(*h)->left,x);
     else if((*h)->data<x)
        insert(&(*h)->right,x);
}
 struct bst *search(struct bst *h,int x)
 {
 	//struct bst *h=*p;
 	if(h==NULL)
 	return h;
 	while(h!=NULL&&h->data!=x)
 	{
 		if(h->data>x)
 		h=h->left;
 		else
 		h=h->right;
	 }
	 return h;
}
 struct bst *inorderSuc(struct bst *h)
 {
                   while(h->left)
                    h=h->left;
        return h;
 }
void delbst(struct bst **h,int x)
{
	//struct bst *t=h;
	struct bst *par=NULL,*t=*h;
	while(t!=NULL&&t->data!=x)
	{
		par=t;
		if(t->data<x)
		t=t->right;
		else
		t=t->left;
	}
	if(!t)
	{
		printf("\nNot found\n");
		return;
	}
	if(t->data==x)
     {
     				struct bst *temp;
                      
                      if((t->left)==NULL&&(t->right)==NULL)
                      {
                     		free(t);
                     		t=NULL;
                      }
                    else if(t->left==NULL)
                    {
                    	if(par->left==t)
                    	par->left=t->right;
                    	else
                    	par->right=t->left;
                    	free(t);
                    	t=NULL;
					}
					else if(t->right==NULL)
					{
						if(par->left==t)
                    	par->left=t->left;
                    	else
                    	par->right=t->right;
                    	free(t);
                    	t=NULL;
					}
                      else
                      {
                      	printf("\nFound %d",par->data);
                      	struct bst *parin=t;
                      	temp=t->right;
                      	while(temp->left!=NULL)
                      	{
                      		parin=temp;
                      		temp=temp->left;
						}
						parin->left=temp->right;
						temp->left=t->left;
						temp->right=t->right;
						if(par->left==t)
						par->left=temp;
						else
						par->right=temp;
						free(t);
						t=NULL;
                      }
                           
 }  
}

int main()
{
	struct bst *r=NULL,*temp;
	int c;
	while(1)
	{
		printf("\nEnter your choice\n");
		printf("\n1-Insert\n2-Inorder\n3-Search\n4->Maximum\n5-Minimum\n6-Delete\n7-Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nEnter the value to insert\n");
				scanf("%d",&c);
				insert(&r,c);
				break;
			case 2:
				printf("\nElements are\n");
				inorder(r);
				break;
			case 3:
				printf("\nEnter value to search\n");
				scanf("%d",&c);
				temp=search(r,c);
				if(temp)
				printf("\nElement found %d",temp->data);
				break;
			case 4:
				temp=maximum(r);
				if(temp)
				printf("\nMaximum of tree is %d",temp->data);
				break;
			case 5:
				temp=minimum(r);
				if(temp)
				printf("\nMinimum of tree is %d",temp->data);
				break;
			case 6:
				printf("\nEnter value to delete\n");
				scanf("%d",&c);
				delbst(&r,c);
				break;
			case 7:
				return 0;
			default :
				printf("\nPlease enter right choice\n");
				break;
			}
	}
}

