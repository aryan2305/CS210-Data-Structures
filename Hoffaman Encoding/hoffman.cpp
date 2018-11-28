#include <bits/stdc++.h>
using namespace std;

#define MAX_Heap_Size 1000

typedef struct _node{
	char data;
	int freq;
	struct _node *left;
	struct _node *right;
}node;

node* heap[MAX_Heap_Size+1];
int Heap_Size=0;

node* CreateNode(char c, int frequency)
{
	node *newNode = (node *)malloc(sizeof(node*));
	newNode->data=c;
	newNode->freq=frequency;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

//return the parent node
int parent(int i)
{
	if(i<=Heap_Size && (i/2)>0)
		return i/2;
	else
		return -1;
}

//return the left node
int left(int i)
{
	if(2*i<=Heap_Size)
		return 2*i;
	else
		return -1;
}

//return the right node
int right(int i)
{
	if(2*i+1<=Heap_Size)
		return 2*i+1;
	else
		return -1;
}

// to search for the character already present
int search(char x,int i)
{
	if(i<=Heap_Size && i>=1)
	{
		if(heap[i]->data==x)
			return i;
		if(left(i)!=-1 && search(x,left(i)))
			return search(x,left(i));
		if(right(i)!=-1 && search(x,right(i)))
			return search(x,right(i));
	}
	return 0;
}

//finding min valued index out of parent and childs
int Min(int i,int l,int r)
{
	int min=i;
	if(l!=-1 && heap[l]->freq<heap[i]->freq)
		min=l;
	if(r!=-1 && heap[r]->freq<heap[min]->freq)
		min=r;
	return min;
}

//to make min heap
void Min_Heapify(int i)
{
	int l=left(i);
	int r=right(i);
	int x = Min(i,l,r);
	if(i!=x)
	{
		swap(heap[i],heap[x]);
		Min_Heapify(x);
	}
}

// to insert element at the correct position 
void Move_up(int i)
{
	while(i>1 && heap[i]->freq<heap[parent(i)]->freq)
	{
			swap(heap[i],heap[parent(i)]);
			i=parent(i);
	}
}

//return the topmost value of the priority queue
node *Extract_min()
{
		node *returnNode = heap[1];
		heap[1]=heap[Heap_Size--];
		Min_Heapify(1);
		return returnNode;
}

//inserting new node
void insert(node *newNode)
{
	if(!search(newNode->data,1))			//new character
	{
		heap[++Heap_Size]=newNode;
		int i=Heap_Size;
		Move_up(i);
	}
	else
	{
		(heap[search(newNode->data,1)]->freq)++;
		int i=search(newNode->data,1);
		Move_up(i);
	}	
}

void printCodes(node * top,int arr[], int index)
{
	if(top->left)
	{
		arr[index]=0;
		printCodes(top->left,arr,index+1);
	}

	if(top->right)
	{
		arr[index]=1;
		printCodes(top->right,arr,index+1);
	}

	if(top->left==NULL && top->right==NULL)
	{
		cout<<top->data<<": ";
		for (int i = 0; i < index; ++i)
		{
			cout<<arr[i];
		}
		cout<<endl;
	}
}

node *buildHoffmanTree()
{
	node *left, *right, *top;
	while(Heap_Size>1)
	{
		left = Extract_min();
		right = Extract_min();

		top = CreateNode('$',left->freq+right->freq);
		top->left=left;
		top->right=right;

		insert(top);
	}
	return Extract_min();
}

void HoffmanCodes()
{
	node *root = buildHoffmanTree();

	int arr[MAX_Heap_Size];
	printCodes(root,arr,0);
}

int main()
{
	string s;
	cin>>s;
	for (int i = 0; i < s.size(); ++i)
	{
		node *minHeapNode = CreateNode(s[i],1);
		insert(minHeapNode);
	}
	/*for (int i = 1; i <=Heap_Size; ++i)
	{
		cout<<heap[i]->data<<" "<<heap[i]->freq<<endl;
	}*/
	HoffmanCodes();
	return 0;
}
