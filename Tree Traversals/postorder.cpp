#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define Max_Stack 1000
typedef struct _node{
	int data;
	int level;
	struct _node* right;
	struct _node* left;
}node;

typedef struct _stack
{
	node* data[Max_Stack];
	int top;
}Stack;

/*-------------Implementation of Stack-------------------*/
Stack* CreateStack()
{
	Stack* thST = (Stack*)malloc(sizeof(Stack*));
	thST->top=-1;
	return thST;
}
bool isEmpty(Stack* stk)
{
	if(stk->top==-1)
		return true;
	else
		return false;
}
bool isFull(Stack* stk)
{
	if(stk->top== Max_Stack-1)
		return true;
	else
		return false;
}
node* Pop(Stack* stk)
{
	if(isEmpty(stk))
	{
		cout<<"call of pop from empty stack"<<endl;
		return NULL;
	}
	else
		return stk->data[(stk->top)--];
}
node* Peek(Stack* stk)
{
	if(isEmpty(stk))
	{
		//cout<<"call of peek from empty stack"<<endl;
		return NULL;
	}
	else
		return stk->data[stk->top];
}
void Push(Stack* stk, node* p)
{
	if(isFull(stk))
		cout<<"Stack full"<<endl;
	else
		stk->data[++(stk->top)] = p;
}
/*---------------------------------------------------------------------*/

node* createNode(int a)
{
	node* Anode=(node*)malloc(sizeof(node*));
	Anode->data=a;
	Anode->left=NULL;
	Anode->right=NULL;
	Anode->level=0;
	return Anode;
}
void postOrder1(node* root)
{
  node* p = root;
	if(p!=NULL)
	{
		postOrder1(p->left);
		postOrder1(p->right);
		cout<<p->data<<" ";
	}
}

void postOrder2(node* root) {
  node* p = root;
  Stack* s = CreateStack();
  do{
  		while(p!=NULL)
  		{
  			//traverse to leftmost node and push the right node of a node before the node
  			if(p->right)
  				Push(s,p->right);
  			Push(s,p); p=p->left;
  		}
  		if(!isEmpty(s))
  		{
  			p=Pop(s); 
  			if(p->right && Peek(s)==p->right)
  			{
  				Pop(s);
  				Push(s,p);
  				p=p->right;
  			}
  			else
  			{
  				cout<<p->data<<" "; 
  				p=NULL;
  			}
  		}
  }while(!isEmpty(s) || p!=NULL);
}
int main()
{
	node* root = createNode(rand()%100);
	//cout<<root->data<<endl;
	root->level=0;
	for (int i = 0; i < 10; ++i)
	{
		int x= rand()%100;
		node* newnode = createNode(x);
		node* p = root;
		int flag=0;
		while(!flag)
		{
			if(p->data>x)
			{
				if(p->left==NULL)
				{
					p->left=newnode;
					//cout<<"(L"<<p->data<<","<<x<<")"<<endl;
					p->left->level=p->level+1;
					flag=1;
				}
				else
				{
					p=p->left;
				}
			}
			else
			{
				if(p->right==NULL)
				{
					p->right=newnode;
					//cout<<"(R"<<p->data<<","<<x<<")"<<endl;
					p->right->level=p->level+1;
					flag=1;
				}
				else
				{
					p=p->right;
				}
			}
		}
	}
	postOrder1(root);
	cout<<endl;
	postOrder2(root);
	cout<<endl;
	return 0;
}
