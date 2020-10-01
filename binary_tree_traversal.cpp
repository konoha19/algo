#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;	
	node *right,*left;
	node(int data)
	{
		this->data=data;
		right=left=NULL;
	}
};

void preorder(node* root)
{
	if(root!=NULL)
	{
		cout<<"["<<root->data<<"] ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<"["<<root->data<<"] ";
	}
}


void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"["<<root->data<<"] ";
		inorder(root->right);
	}
}

int main()
{
	node* root=new node(12);
	node* n;
	root->left=new node(10);
	root->right=new node(13);
	root->left->right=new node(14);
	root->right->left=new node(15);
	root->right->right=new node(16);
	cout<<"\nPreorder";
	preorder(root);
	cout<<"\nPostorder";
	postorder(root);
	cout<<"\nInorder";
	inorder(root);
	cout<<"\n";
}
