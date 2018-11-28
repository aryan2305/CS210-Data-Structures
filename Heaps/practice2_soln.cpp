#include <bits/stdc++.h>
using namespace std;

#define MAX_Heap_Size 1000
int heap[MAX_Heap_Size+1];
int Heap_Size=0;
int ind=0;
int valind=0;
string log1[MAX_Heap_Size];
int val[MAX_Heap_Size];
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

void insert(int x)
{
	heap[++Heap_Size]=x;
	int i=Heap_Size;
	while(i>1 && heap[i]<heap[parent(i)])
	{
		swap(heap[i],heap[parent(i)]);
		i=parent(i);
	}
}

int Min(int i,int l, int r)
{
	int minimum = i;
	if(l<=Heap_Size && l!=-1 && heap[l]<heap[i])
		minimum=l;
	if(r<=Heap_Size && r!=-1 && heap[r]<heap[minimum])
		minimum=r;
	return minimum;
}

void Min_Heapify(int i)
{
	int l=left(i);
	int r=right(i);
	int x=Min(i,l,r);
	if(x!=i)
	{
		swap(heap[x],heap[i]);
		Min_Heapify(x);
	}
}

int removeMin()
{
	heap[1]=heap[Heap_Size--];
	int i=1;
	Min_Heapify(i);
}
int getMin(int x)
{
	if(Heap_Size==0)
	{
		insert(x);
		log1[ind++]="insert";
		val[valind++]=x;
		return 1;		
	}
	if(heap[1]==x)
		return heap[1];
	else
	{
		if(heap[1]>x)
		{
			insert(x);
			log1[ind++]="insert";
			val[valind++]=x;
			//cout<<"insert "<<x<<endl;
		}
		else
		{
			removeMin();
			log1[ind++]="removeMin";
			//cout<<"removeMin"<<endl;
			getMin(x);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <=n ; ++i)
	{
		string s;
		int x;
		cin>>s;
		if(s=="removeMin")
		{
			removeMin();
			log1[ind++]=s;
			//cout<<s<<endl;
			continue;
		}
		cin>>x;		
		if(s=="insert")
		{
			insert(x);
			log1[ind++]=s;
			val[valind++]=x;
			//cout<<s<<" "<<x<<endl;
		}
		else if(s=="getMin")
		{
			getMin(x);
			log1[ind++]=s;
			val[valind++]=x;
			//cout<<s<<" "<<x<<endl;
		}		
	}
	cout<<ind<<endl;
	int j=0;
	for (int i = 0; i < ind; ++i)
	{
		cout<<log1[i];
		if(log1[i]=="removeMin")
		{
			cout<<endl;
			continue;
		}
		else
		{
			cout<<" "<<val[j]<<endl;
			j++;
		}
	}
	return 0;
}