#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define Max_Stack 1000
typedef struct _node{
	int data;
	struct _node* right;
	struct _node* left;
	bool rightSccessor;
}node;

node* createNode(int a)
{
	node* Anode=(node*)malloc(sizeof(node*));
	Anode->data=a;
	Anode->left=NULL;
	Anode->right=NULL;
	Anode->rightSccessor=false;
	return Anode;
}
node * search(int a,node* root)
{
  	node*  p = root;
	if(p!=NULL)
	{
		if(p->data==a) return p;
		return search(a,p->left);
		if(p->rightSccessor==false)
			return search(a,p->right);		
	}
}

void setLeft(node* p, node* q)
{
	if(p && q)
	{
		if(p->left==NULL) p->left=q;
		else
			cout<<"invalid input left node already exist"<<endl;
	}
}

void setRight(node* p, node* q)
{
	if(p && q)
	{
		if(p->right==NULL)
		{
			p->right=q;
			q->right=p;
			q->rightSccessor=true;
			p->rightSccessor=false;
		}
		else
		{
			q->right=p->right;
			p->right=q;
			q->rightSccessor=true;
			p->rightSccessor=false;
		}
	}
}
void inOrder1(node* root)
{
  node* p = root;
  node* q;
  do{
  		while(p!=NULL)
  		{
  			q=p;
  			p=p->left;
  		}
  		if(q!=NULL)
  		{
  			cout<<q->data<<" ";
  			p=q;
  			p=p->right;
  		}
  		while(q->rightSccessor && p!=NULL)
  		{
  			cout<<p->data<<" ";
  			q=p;
  			p=p->right;
  		}
  }while(q);
}
int main()
{
	cout<<"Enter root node value"<<endl;
	int x;
	cin>>x;
	node* root = createNode(x);
	int n;
	cout<<"Number of Nodes="<<endl;
	cin>>n;
	cout<<"Enter othe nodes in the format node1 node2 L/R"<<endl;
	for (int i = 0; i < n; ++i)
	{
		int num1,num2;
		char side;
		cin>>num1>>num2>>side;
		node* p= search(num1,root);
		node* q= createNode(num2);
		if(side=='L')
			setLeft(p,q);
		else
			setRight(p,q);
	}
	inOrder1(root);
	cout<<endl;
	return 0;
}
