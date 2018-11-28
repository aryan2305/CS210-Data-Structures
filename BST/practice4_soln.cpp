#include<bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define MAX_FILES 1000

typedef struct _node{
	string name;
	struct _node* next;	
	int top;
	int rear;
	string files[MAX_FILES];
}node;

node* createNode(string x)
{
	node* nd = (node*)malloc(sizeof(node*)*50);
	nd->name=x;
	nd->next=NULL;
	nd->top=-1;
	nd->rear=-1;
	return nd;
}

void CreateFile(node* folder, string name)
{
	node* p= folder;
	p->files[++(p->rear)]=name;
	cout<<"Created "<<name<<" in "<<folder->name<<endl;
}

node* newFolder(node* parent,string name)
{
	node* child = createNode(name);
	parent->next=child;
	cout<<"Made "<<name<<" in "<<parent->name<<endl;
	return child;
}

node* back(node* root,node* currFolder)
{
	node*p = root;
	if(currFolder==p)
	{
		cout<<"Cannot back from root"<<endl;
		return root;
	}
	while(p->next != currFolder)
		p=p->next;
	p->next=NULL;
	cout<<"Back from "<<currFolder->name<<endl;
	free(currFolder);
	return p;
	
}

void delFile(node* folder)
{
	if(folder->rear==folder->top)
	{
		cout<<"Cannot delete from "<<folder->name<<endl;
		return;
	}
	string s = folder->files[++(folder->top)];
	cout<<"Deleted "<<s<<" from "<<folder->name<<endl;
}
int main()
{
	string str = "root";
	node *root=createNode(str);
	node* currFolder = root;
	for(int i=0;;i++)
	{
		string s1,s2;
		cin>>s1;

		if(s1=="-1")
			break;

		if(s1=="DELETE")
		{
			delFile(currFolder);
			continue;
		}
		else if(s1=="BACK")
		{
			currFolder=back(root,currFolder);
			continue;
		}

		cin>>s2;
		if(s1=="CREATE")
		{
			CreateFile(currFolder,s2);
		}
		else if(s1=="NEW")
		{
			currFolder=newFolder(currFolder,s2);
		}	
	}
	return 0;
}