#include <bits/stdc++.h>
using namespace std;

#define MAX_Heap_Size 1000
int heap[MAX_Heap_Size+1];
int Heap_Size=0;

int parent(int i)
{
	if(i>1)
		return i/2;
	else if(i==1)
		cout<<"root doesn't have parent"<<endl;
	else
		cout<<"heap not made yet"<<endl;
}

int left(int i)
{
	if(i>=1)
		return 2*i;
	else
		cout<<"heap not made"<<endl;
}

int right(int i)
{
	if(i>=1)
	{
		return 2*i+1;
	}
	else
		cout<<"heap not made yet"<<endl;
}

int max(int i, int l, int r)
{
	int largest=i;
	if(l<=Heap_Size && heap[l]>heap[i])
		largest=l;
	if(r<=Heap_Size && heap[r]>heap[largest])
		largest=r;

	return largest;	
}
/*THIS IS SAME AS MAX_HEAPIFY FUNCTION*/
void Move_down(int i)
{
	int l=left(i);
	int r=right(i);
	int x=max(i,l,r);
	if(x!=i)
	{
		swap(heap[x],heap[i]);
		Move_down(x);
	}
}

void Move_up(int i)
{
	while(i>1 && heap[i]>heap[parent(i)])
	{
		swap(heap[i],heap[parent(i)]);
		i=parent(i);
	}
}

/*--------PRIORITY QUEUE IMPLEMENTATION-----------------*/

void insert(int x)
{
	Heap_Size++;
	heap[Heap_Size]=x;
	Move_up(Heap_Size);
}

void Heap_delete(int index)
{
	heap[index]=heap[Heap_Size--];
	if(heap[index] > heap[parent(index)])
		Move_up(index);
	else
		Move_down(index);
}

void increase_key(int index, int x)
{
	if(x < heap[index])
	{
		cout<<"ERROR: value of the node already greater than the inserted value"<<endl;
	}
	else
	{
		heap[index]=x;
		Move_up(index);
	}
}

void extract_max()
{
	int return_elem = heap[1];
	heap[1]=heap[Heap_Size--];
	Move_down(1);
}

void merge(int heap1[] , int heap2[] , int heap3[])
{
	
}

int main()
{
	int n;
	cin>>n;
	int x;
	cin>>x;
	heap[++Heap_Size]=x;
	for (int i = 2; i <=n ; ++i)
	{
		cin>>heap[++Heap_Size];
	}
	Build_heap();
	for (int i = 1; i <=Heap_Size ; ++i)
	{
		cout<<heap[i]<<endl;
	}
	return 0;
}