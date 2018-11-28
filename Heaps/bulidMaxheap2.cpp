#include <bits/stdc++.h>
using namespace std;

/*--------BOTTOM UP OR FLOYD METHOD O(n)-----------------*/

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

void Max_Heapify(int i)
{
	int l=left(i);
	int r=right(i);
	int x=max(i,l,r);
	if(x!=i)
	{
		swap(heap[x],heap[i]);
		Max_Heapify(x);
	}
}

void Build_heap()
{
	int n = Heap_Size;
	for (int i = n/2; i >=1 ; --i)
	{
		Max_Heapify(i);
	}
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