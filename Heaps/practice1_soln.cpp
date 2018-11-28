#include <bits/stdc++.h>
using namespace std;

int Max_Heap_Size=1000000;
int Heap_Size=0;

/*---------William Method of making heap----------------*/
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

void Move_up(int *a)
{
	int i=Heap_Size;
	while(i>1 && a[i]<a[parent(i)])
	{
		swap(a[i],a[parent(i)]);
		i=parent(i);
	}
}

void insert(int *a, int x)
{
		a[++Heap_Size]=x;
		Move_up(a);	
}

int Min(int *a, int i,int l, int r)
{
	int minimum = i;
	if(l<=Heap_Size && l!=-1 && a[l]<a[i])
		minimum=l;
	if(r<=Heap_Size && r!=-1 && a[r]<a[minimum])
		minimum=r;
	return minimum;
}

void DeleteTop(int *a,int i)
{
	swap(a[i],a[Heap_Size--]);
	while(i<=Heap_Size)
	{
		int x;
		if(left(i)==-1 && right(i)==-1)
			break;
		else
			x = Min(a,i,left(i),right(i));

		if(x!=i)
		{
			swap(a[x],a[i]);
			i=x;
		}
		else
			break;
	}
}

void printMin(int *a,int k)
{
	while(k--)
	{
		cout<<a[1]<<" ";
		DeleteTop(a,1);
	}
}
int main(int argc, char const *argv[])
{
	ifstream fin;
	fin.open(argv[1]);
	int line;
	int size;
	if(fin)
	{
		fin>>line;
		size=line;
	}
	
	int heap[size+1];
	clock_t start = clock();
	while(fin)
	{
		fin>>line;
		insert(heap,line);
	}
	fin.close();
	/*for (int i = 1; i <= size; ++i)
	{
		cout<<heap[i]<<endl;
	}*/
	int k;
	cin>>k;
	printMin(heap,k);
	cout<<endl;
	clock_t end = clock();
	double time = (double(end - start))/CLOCKS_PER_SEC;
	cout<<time<<endl;
	return 0;
}