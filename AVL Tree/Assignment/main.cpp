#include <bits/stdc++.h>
#include "node.h"
#include "avl.h"

using namespace std;

int main()
{
	vector<int>array;
	int x;
	while(cin>>x)
	{
		array.push_back(x);
	}
	sort(array.begin(),array.end());
	int n = array.size();
	vector<int>final;
	queue<pair<int,int>>q;
	q.push(make_pair(0,n-1));
	while(!q.empty())
	{
		pair<int,int>p = q.front();
		q.pop();
		//cout<<"debug"<<p.first<<" "<<p.second<<endl;
		int mid = p.first + (p.second-p.first)/2;
		//cout<<" "<<mid<<" "<<array[mid]<<endl;
		final.push_back(array[mid]);
		if(mid+1<=p.second)
			q.push(make_pair(mid+1,p.second));
		if(p.first<=mid-1)
			q.push(make_pair(p.first,mid-1));
	}
	

	avl* tree = new avl();

	for (int i = 0; i < final.size(); ++i)
	{
		node* n1 = new node(final[i]);
		tree->treeInsertNode(n1);
	}
	
	tree->updateNodeNumbers(tree->head);
	cout<<"Sequence of insertions: ";
	for (int i = 0; i < final.size(); ++i)
	{
		cout<<final[i]<<" ";
	}
	cout<<endl<<"Tree structure"<<endl;

	tree->preorderTraversal(tree->head);	

	return 0;
}