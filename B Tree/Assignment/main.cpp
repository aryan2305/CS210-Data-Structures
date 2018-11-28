#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//declaration of node class
class node{
	public:
	int nodeId;
	int ParentId;
	int numKeys;
	int numChild;
	int childCount;
	int depth;
	bool isLeaf;		//to check if the node is a leaf node
	bool isroot;		//to check if the node is root
	node* parent;
	node** child;		//to store the child pointers
	node(int nId, int PId, int keynum, int childNum);
};

int MAX_DEGREE;   //globaly declaring the max key in the node


node::node(int nId, int PId, int keynum, int childNum)  //constructor for node class
{
	this->nodeId=nId;
	this->ParentId=PId;
	this->numKeys=keynum;
	this->numChild=childNum;
	this->parent=NULL;
	this->depth=0;
	this->childCount=0;
	this->isroot=false;
	this->child = new node*[childNum];
	for (int i = 0; i < childNum; ++i)
	{
		this->child[i]=NULL;
	}
	if(childNum)		//if the number of childrens are non zero then the node is not a leaf node
		this->isLeaf=false;
	else					//else it is a leaf node
		this->isLeaf=true;
}

node* findParent(node* root, int Id)			//function to find the parent of the node
{
	node* p = root;
	if(p==NULL)		//if the p is NULL then we have reached the end of the tree
		return NULL;

	if(p->nodeId == Id)		//check if the node id of the parent matches with query id
		return p;

	for (int i = 0; i < p->childCount; ++i)
	{
		/*checking recursively in the child*/
		if(findParent(p->child[i],Id))		
			return findParent(p->child[i],Id);
	}
	return NULL;
	
}
int CheckMinimumOccupancy(node* root)			// function to check the minimum occupancy condition
{
	node* p = root;
	if(p==NULL)
		return 0;

		
	if(!(p->isroot) && p->numKeys < MAX_DEGREE/2)		//if the node is root then it does not hold the minimum occupancy conditiion
		return p->nodeId;
	else
	{
		for (int i = 0; i < p->numChild; ++i)
		{
			if(CheckMinimumOccupancy(p->child[i]))
			return CheckMinimumOccupancy(p->child[i]);
		}
	}
	return 0;
}

int main()
{
	vector<int>leafDepth;	//to store the depth of the leaf node
	vector<int>leafId;		//to store the corresponding indices of the leaf node

	int n,x;
	cin>>n>>x;
	MAX_DEGREE=n;		//setting the max key to the user input

	/*taking input for the root node. first node will always be the root node as 
	it is the parent of all the nodes and it is given that the parent appears before the child*/
	
	int nId,PId,keynum,childNum;
	cin>>nId>>PId>>keynum>>childNum;	
	node* root = new node(nId,PId,keynum,childNum);
	root->isroot=true;

	if(root->isLeaf)		//to check if the tree has only one node then root is also a leaf node
	{
		leafDepth.push_back(root->depth);
		leafId.push_back(root->nodeId);
	}

	

	int flag = 0;
	int wrongNode;

	for (int i = 0; i < x-1; ++i)
	{
		cin>>nId>>PId>>keynum>>childNum;
		node* newNode = new node(nId,PId,keynum,childNum);

		if(!(newNode->isLeaf) && childNum != keynum+1) //checking condition that every node satisfies the condition Children count = Key count + 1
		{
			flag=1;
			wrongNode=nId;
		}
		node* Parent = findParent(root,PId); //find parent of the node
		newNode->parent = Parent;
		newNode->depth=Parent->depth+1;  //setting depth
		
		if(newNode->isLeaf)		//if node is leaf push in the corrensponding vectors its id and depth
		{
			leafDepth.push_back(newNode->depth);
			leafId.push_back(newNode->nodeId);
		}
		Parent->child[Parent->childCount++]=newNode;
	}

	if(flag) //checking condition that every node satisfies the condition Children count = Key count + 1
	{
		cout<<"Answer: This cannot be a valid B Tree."<<endl;
		cout<<"Reason: "<<wrongNode<<" does not satisfy the requirement that Children count = Key count + 1."<<endl;
		return 0;
	}
	
	if(CheckMinimumOccupancy(root))  //checking minimum occupancy condition
	{
		int id = CheckMinimumOccupancy(root);
		cout<<"Answer: This cannot be a valid B Tree."<<endl;
		cout<<"Reason: "<<id<<" does not have minimum occupancy."<<endl;
		return 0;

	}
	/*To check that every leaf node have the same depth*/
	int currDepth=leafDepth[0];
	int flag2=0;
	int node1,node2;
	for (int i = 1; i < leafDepth.size(); ++i)
	{
		if(leafDepth[i]!=currDepth)		//comparing depth of each leaf node
		{
			node1=leafId[0];
			node2=leafId[i];
			flag2=1;
			break;
		}
	}

	if(flag2) //if two leaf nodes with diffrent depth are found
	{
		cout<<"Answer: This cannot be a valid B Tree."<<endl;
		cout<<"Reason: "<<node1<<" and "<<node2<<" are a pair of leaf nodes that do not have the same depth."<<endl;
		return 0;
	}

	//else tree can be valid b tree
	cout<<"This can be a valid B Tree"<<endl;
	return 0;
}