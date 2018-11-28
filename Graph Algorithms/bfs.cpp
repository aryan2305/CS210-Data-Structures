#include<bits/stdc++.h>
using namespace std;
typedef struct _node{
	char vertex;
	struct _node *parent;
	int d;
	struct _node *next;
}node;

const int MAX_LIST_SIZE = 1000;
int list_size=0;
node * adjList[MAX_LIST_SIZE];
int color[MAX_LIST_SIZE]={0};
/*---------queue implementation---------*/
const int MAX_QUEUE_SIZE=1000;
typedef struct _queue{
	int top;
	int rear;
	node * data[MAX_QUEUE_SIZE];
}que;

que *CreateQueue()
{
	que *thQ = (que *)malloc(sizeof(que *));
	thQ->top=0;
	thQ->rear=0;
	return thQ;
}

bool isEmpty(que* thQ)
{
	if(thQ->rear==thQ->top)
		return true;
	else
		return false;
}

bool isFull(que *thQ)
{
	if(thQ->rear==MAX_QUEUE_SIZE)
		return true;
	else
		return false;
}

void enqueue(que *thQ,node* x)
{
	if(!isFull(thQ))
		thQ->data[thQ->rear++]=x;

}

node * dequeue(que *thQ)
{
	if(!isEmpty(thQ))
		return thQ->data[thQ->top++];
	else
		return NULL;
}
/*--------------------*/
int currTime =0;
node *CreateNode(char c)
{
	node *anode=(node *)malloc(50*sizeof(node *)) ;
	anode->vertex =c;
	anode->parent=NULL;
	anode->next =NULL;
	anode->d=0;
	return anode;
}

void Push(node *p,node *q)
{
	node *temp=p;
	while(temp->next !=NULL)
		temp=temp->next;
	temp->next=q;
}

void bfs(node *start)
{
	node * s = start;
	s->d=0;
	que * q = CreateQueue();
	enqueue(q,s);
	color[s->vertex-'q']=1;
	while(!isEmpty(q))
	{
		node * u = dequeue(q);
		node * temp=u->next;
		while(temp)
		{
			if (color[temp->vertex - 'q']==0)
			{
				color[temp->vertex - 'q']=1;
				adjList[temp->vertex - 'q']->parent=u;
				enqueue(q,adjList[temp->vertex - 'q']);
			}
			temp=temp->next;
		}
		color[u->vertex-'q']=2;
	}
}

void printPath(node * x)
{
	if(x)
	{
		printPath(x->parent);
		cout<<x->vertex<<" ";
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

	bfs(adjList[0]);
	for (int i = 0; i < n; ++i)
	{
		printPath(adjList[i]);
		cout<<endl;
	}
	return 0;
}