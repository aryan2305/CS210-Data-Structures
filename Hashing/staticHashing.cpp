#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class HashTable{
	int b;
	vector<int>*buckets;

	public:
		HashTable(int bcount);
		int hashValue(int entry);
		void insert(int entry);
		bool search(int entry);
		void delValue(int entry);
		void PrintHashTable();
};

HashTable::HashTable(int bcount){
	this->b=bcount;
	this->buckets = new vector<int>[bcount];
}

int HashTable::hashValue(int entry){

	int value = entry%(this->b);

	return value;
}

void HashTable::insert(int entry){
	int bucketIndex = hashValue(entry);

	this->buckets[bucketIndex].push_back(entry);
}

bool HashTable::search(int entry){
	int bucketIndex = hashValue(entry);
	bool present  = false;

	for (int i = 0; i <this->buckets[bucketIndex].size() ; ++i)
	{
		if(this->buckets[bucketIndex][i]==entry)
			present=true;	
	}

	return present;
}

void HashTable::delValue(int entry){
	if(!search(entry))
	{
		cout<<entry<<" is not present in the HashTable"<<endl;
		return;
	}
	int bucketIndex = hashValue(entry);

	for (int i = 0; i <this->buckets[bucketIndex].size() ; ++i)
	{
		if(this->buckets[bucketIndex][i]==entry)
		{
			this->buckets[bucketIndex].erase(this->buckets[bucketIndex].begin()+i);
		}	
	}
}

void HashTable::PrintHashTable(){

	for (int i = 0; i < this->b; ++i)
	{
		cout<<"Bucket No. "<<i<<" : ";
		for (int j = 0; j <this->buckets[i].size() ; ++j)
		{
			cout<<this->buckets[i][j]<<", ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	HashTable *hash = new HashTable(n);
	int x;
	cin>>x;
	while(x!=-1)
	{
		hash->insert(x);
		cin>>x;
	}
	hash->PrintHashTable();
	
	cout<<"Enter a value to search in Hash Table"<<endl;
	cin>>x;
	if(hash->search(x))
		cout<<"Present"<<endl;
	else
		cout<<"Not present"<<endl;

	cout<<"Enter a value to delete in Hash Table"<<endl;
	cin>>x;
	hash->delValue(x);
	
	hash->PrintHashTable();
	return 0;
}