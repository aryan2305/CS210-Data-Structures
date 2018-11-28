#include<bits/stdc++.h>
using namespace std;
typedef struct _node{
	char vertex;
	struct _node *parent;
	int dt;
	int ft;
	struct _node *next;
}node;

const int MAX_LIST_SIZE = 1000;
int list_size=0;
node * adjList[MAX_LIST_SIZE];
int color[MAX_LIST_SIZE]={0};

int currTime =0;
/*---------------------stack implementation---------------------------*/
const int MAX_STACK_SIZE=1000;
typedef struct _stack{
	int top;
	node * data[MAX_STACK_SIZE];
}stk;

stk *CreateStack()
{
	stk *thST = (stk *)malloc(sizeof(stk *));
	thST->top=-1;
	return thST;
}

bool isEmpty(stk* thST)
{
	if(thST->top==-1)
		return true;
	else
		return false;
}

bool isFull(stk *thST)
{
	if(thST->top==MAX_STACK_SIZE)
		return true;
	else
		return false;
}

void Push(stk *thST,node* x)
{
	if(!isFull(thST))
		thST->data[++thST->top]=x;

}

node * Pop(stk *thST)
{
	if(!isEmpty(thST))
		return thST->data[thST->top--];
	else
		return NULL;
}
/*--------------------------------------------------------------------*/
node *CreateNode(char c)
{
	node *anode=(node *)malloc(50*sizeof(node *)) ;
	anode->vertex =c;
	anode->parent=NULL;
	anode->next =NULL;
	anode->dt=0;
	anode->ft=0;
	return anode;
}

void Push(node *p,node *q)
{
	node *temp=p;
	while(temp->next !=NULL)
		temp=temp->next;
	temp->next=q;
}

void dfs(node * start)
{
	node *s= start;
	color[s->vertex-'q']=1;
	currTime++;
	s->dt=currTime;
	node * temp = s->next;
	while(temp!=NULL)
	{
		if(color[temp->vertex-'q'] == 0)
		{
			color[temp->vertex-'q']=1;
			cout<<"( "<<s->vertex<<","<<temp->vertex<<" )"<<endl;
			temp->parent=s;
			dfs(temp);
			
		}
		temp=temp->next;
	}
	color[s->vertex-'q']=2;
	currTime++;
	s->ft=currTime;
}

void dfs2(node *start)
{
	stk *s= CreateStack();
	Push(s,start);

	while(!isEmpty(s))
	{
		node  *r = Pop(s);
		if(color[r->vertex-'q']==0)
		{
			color[r->vertex-'q']=1;
			currTime++;
			r->dt=currTime;
		}
		node * temp= r->next;
		while(temp!=NULL)
		{
			if(color[temp->vertex-'q'] == 0)
			{
				color[temp->vertex-'q']=1;
				cout<<"( "<<r->vertex<<","<<temp->vertex<<" )"<<endl;
				temp->parent=r;
				Push(s,temp);
			
			}
			temp=temp->next;
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	for (int i = 0; i <n; ++i)
	{
		adjList[i]=CreateNode('q'+i);
	}
	char a,b;
	for (int i = 0; i < e; ++i)
	{
		cin>>a>>b;
		node *child = CreateNode(b);
		Push(adjList[a-'q'],child);
	}

	for (int i = 0; i < n; ++i)
	{
		if(color[adjList[i]->vertex-'q']==0)
		{
			dfs2(adjList[i]);
		}
	}
	return 0;
}