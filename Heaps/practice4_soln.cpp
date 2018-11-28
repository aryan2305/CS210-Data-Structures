#include <bits/stdc++.h>
using namespace std;

#define Max_Heap_Size 1000
int heap[Max_Heap_Size+1];
int Heap_Size=0;

int parent(int i)
{
	if(i==1)
	{
		cout<<"root node doesn't have the parent"<<endl;
		return 1;
	}
	else
		return i/2;
}

int left(int i)
{
	if(2*i<=Heap_Size)
		return 2*i;
	else return-1;
}

int right(int i)
{
	if((2*i+1) <= Heap_Size)
		return 2*i+1;
	else
		return -1;
}

int Max(int i,int l,int r)
{
	int largest = i;
	if(l<=Heap_Size && l!=-1 && heap[l]>heap[i])
		largest = l;
	if(r<=Heap_Size && r!=-1 && heap[r]>heap[largest])
		largest=r;
	return largest;
}

void Max_Heapify(int i)
{
	int l=left(i);
	int r=right(i);
	int x=Max(i,l,r);
	if(i!=x)
	{
		swap(heap[i],heap[x]);
		Max_Heapify(x);
	}
}
void insert(int x)
{
	heap[++Heap_Size]=x;
	int i=Heap_Size;
	while(i>1 && heap[i]>heap[parent(i)])
	{
		swap(heap[i],heap[parent(i)]);
		i=parent(i);
	}
}

void Merge_Heap(int *heap1, int *heap2,int *heap3)
{
	heap3=heap1;
	Heap3_Size=Heap1_Size;
	for (int i = 1; i <=Heap_Size2 ; ++i)
	{
		insert(heap3,heap2[i]);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int k;
	cin>>k;
	for (int i = 0; i <k; ++i)
	{
		insert(a[i]);
	}	
	for (int i = k; i < n; ++i)
	{
		if(heap[1]>a[i])
		{
			heap[1]=a[i];
			Max_Heapify(1);
		}
	}
	cout<<heap[1]<<endl;
	return 0;
}