#include<bits/stdc++.h>
using namespace std;
typedef struct _node{
	int data;
	struct _node* parent;
	struct _node* left;
	struct _node* right;	
}node;

node* createNode(int x)
{
	node* nd = (node*)malloc(sizeof(node*)*50);
	nd->data=x;
	nd->left=NULL;
	nd->right=NULL;
	nd->parent=NULL;
	return nd;
}

void insert(node* root, int key)
{
	node*p =root;
	if(p!=NULL)
	{
		if(p->data > key)
		{
			if(p->left)
				insert(p->left,key);
			else
				{
					node* z = createNode(key);
					p->left=z;
					z->parent=p;
				}
		}
		else
		{
			if(p->right)
				insert(p->right,key);
			else
				{
					node* z = createNode(key);
					p->right=z;
					z->parent = p;
				}
		}
	}

}

node* bst_search(node* root, int key)
{
	node*p=root;
	if(p!=NULL)
	{
		if(p->data==key)
			return p;
		else
		{
			if(p->data > key)
			{
				return bst_search(p->left,key);
			}
			else
				return bst_search(p->right,key);
		}
	}
	return NULL;
}

bool bst_compare(node* root1,node* root2)
{
	node* p = root1;
	node* q = root2;
	if(p==NULL && q==NULL)
		return true;
	if(p==NULL || q==NULL)
		return false;
	if(p && q)
	{
		if(p->data!=q->data)
			return false;
		if(!bst_compare(p->left,q->left))
			return false;
		if(!bst_compare(p->right,q->right))
			return false;
	}
	return true;
}
int main()
{
	cout<<"for first bst="<<endl;
	int n;
	cin>>n;
	node* root1 =NULL; 
	
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin>>a;
		if(i==0)
		{
			root1 = createNode(a);
			continue;
		}
		insert(root1,a);
	}

	cout<<"for second bst="<<endl;
	int n2;
	cin>>n2;
	node* root2 = NULL;
	for (int i = 0; i < n2; ++i)
	{
		int a;
		cin>>a;
		if(i==0)
		{
			root2 = createNode(a);
			continue;
		}
		insert(root2,a);
	}
	if(bst_compare(root2,root1))
		cout<<"equal"<<endl;
	else
		cout<<"not equal"<<endl;
	return 0;
}