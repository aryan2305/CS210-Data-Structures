#include <bits/stdc++.h>
using namespace std;

/*--------TOP DOWN OR WILLIAM METHOD O(n*log(n))-----------------*/

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

void Insert(int x)
{
	heap[++Heap_Size]=x;
	int i=Heap_Size;
	while(i>1 && heap[i]>heap[parent(i)])
	{
		swap(heap[i],heap[parent(i)]);
		i=parent(i);
	}
}

void Build_heap(int n)
{
	for (int i = 2; i <=n ; ++i)
	{
		int x;
		cin>>x;
		Insert(x);
	}
}
int main()
{
	int n;
	cin>>n;
	int x;
	cin>>x;
	heap[++Heap_Size]=x;
	Build_heap(n);
	for (int i = 1; i <=Heap_Size ; ++i)
	{
		cout<<heap[i]<<endl;
	}
	return 0;
}