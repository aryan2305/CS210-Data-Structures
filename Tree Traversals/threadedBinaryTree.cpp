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
node* leftmost(node* root)
{
	if(root==NULL)
		return NULL;
	else
	{
		while(root->left)
			root=root->left;
		return root;
	}
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
		if(p->left==NULL) 
		{
			//cout<<p->data<<" "<<q->data<<"debug2"<<endl;
			p->left=q;
			q->right=p;
			q->rightSccessor=true;
		}
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
		}
		else
		{
			if(p->rightSccessor==true)
			{
				q->right=p->right;
				p->right=q;
				q->rightSccessor=true;
				p->rightSccessor=false;
			}
			else
				cout<<"Invalid input right node already exist"<<endl;
		}
	}
}


void inOrder1(node* root)
{
  node* p = root;
	if(p!=NULL)
	{
		inOrder1(p->left);
		cout<<p->data<<" ";
		if(!p->rightSccessor && p->right)
			inOrder1(p->right);

	}
}
void inOrder3(node* root)
{
  node* p = leftmost(root);
  while(p!=NULL)
  {
  	cout<<p->data<<endl;
  	if(p->rightSccessor==true)
  		p=p->right;
  	else
  	{
  		p=leftmost(p->right);
  	}
  }
}
void preOrder3(node* root)
{
	node* p= root;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		if(p->left)
			p=p->left;
		else if(p->right)
		{
			while(p->rightSccessor)
				{
					//cout<<p->right->data<<" "<<p->right->right->data<<"debug"<<endl;
					p=p->right;
				}
				p=p->right;
		}
	}
	
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
	/*------------------Hard core INPUT--------------------*/
	// node* root = createNode(55);
	// setLeft(root,createNode(27));
	// setRight(root,createNode(80));
	// setLeft(root->right,createNode(60));
	// setRight(root->right->left,createNode(70));
	// setRight(root->left,createNode(28));
	// setLeft(root->left,createNode(11));
	root->rightSccessor=false;
	//node* p=search(70,root);
	//p->rightSccessor=true;
	inOrder3(root);
	//preOrder3(root);
	cout<<endl;
	return 0;
}
