#include "tree.h"

extern struct node *root;

void insert(char value[1000])
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	
	strcpy(temp->key,value);
	temp->left=NULL;
	temp->right=NULL;
	
	root=insertr(temp,root);
	
}

struct node *insertr(struct node *temp,struct node *root)
{
	if(root==NULL)
	{
		return temp;
	}
	
	else if(strcmp(root->key,temp->key)>0)
	{
		root->left=insertr(temp,root->left);
	}
	
	else if(strcmp(root->key,temp->key)!=0)
	{
		root->right=insertr(temp,root->right);
	}
	
	return root;
}

void traverse()
{
	int i;
	char string[1000][1000];
	i=0;
	i=inOrder(root,string,i);
	graph(string,i);
}

int inOrder(struct node *root,char string[1000][1000],int i)
{
	int c=0;
	
	if(root!=NULL)
	{
		c+=inOrder(root->left,string,i);
		strcpy(string[i+c++],root->key);
		c+=inOrder(root->right,string,i+c);
	}
	
	return c;
}

