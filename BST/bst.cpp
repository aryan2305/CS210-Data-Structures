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
void insert_recursive(node* root, int key)
{
	node*p =root;
	if(p!=NULL)
	{
		if(p->data > key)
		{
			if(p->left)
				insert_recursive(p->left,key);
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
				insert_recursive(p->right,key);
			else
				{
					node* z = createNode(key);
					p->right=z;
					z->parent = p;
				}
		}
	}

}

void insert2(node* root,int key)
{
	node*p=root;
	node*q=NULL;
	while(p!=NULL && p->data!=key)
	{
		q=p;
		if(p->data > key)
			p=p->left;
		else
			p=p->right;
	}
	if(p!=NULL)
	{
		cout<<"Number already exist"<<endl;
		return;
	}

	node* z = createNode(key);
	if(q!=NULL)
	{
		if(q->data > key)
			{
				q->left = z;
				z->parent=q;
			}
		else
			{
				q->right = z;
				z->parent=q;
			}
	}
}

node* bst_search1(node* root, int key)
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
				return bst_search1(p->left,key);
			}
			else
				return bst_search1(p->right,key);
		}
	}
	return NULL;
}

node* bst_search2(node* root, int key)
{
	node* p= root;
	while(p!=NULL && p->data!=key)
	{
		if(p->data > key)
		{
			p=p->left;
		}
		else
			p=p->right;
	}
	return p;
}

node* bst_minimum(node* root)
{
	node*p = root;
	while(p->left!=NULL)
		p=p->left;
	return p;
}

node* bst_maximum(node* root)
{
	node*p = root;
	while(p->right!=NULL)
		p=p->right;
	return p;
}

node* successor(node*  parent_node)
{
	node* p = parent_node;
	if(p->right)
		return bst_minimum(p->right);
	else
	{
		node* q = p->parent;
		while(q!=NULL && p==q->right)
		{
			p=q;
			q=q->parent;
		}
		return q;
	}
}

void del(node* delNode)
{
	node* p = delNode;

	if(p->left==NULL && p->right==NULL)
	{
		node* q= p->parent;
		if(q->left==p)
			q->left=NULL;
		else
			q->right=NULL;
		free(p);
	}
	else if(p->left && p->right)
	{
		node * q = successor(p);
		p->data = q->data;
		del(q);
	}
	else
	{
		if(p->left)
		{
			node* q =p->parent;
			if(q->right==p)
				q->right = p->left;
			else
				q->left=p->left;

			free(p);
		}
		else
		{
			node* q = p->parent;
			if(q->right==p)
				q->right = p->right;
			else
				q->left=p->right;

			free(p);
		}
	}
}
void inorder(node* root)
{
	node* p= root;
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}	
}
int main()
{
	int n;
	cin>>n;
	int x;
	cin>>x;
	node* root = createNode(x);
	for (int i = 1; i < n; ++i)
	{
		int a;
		cin>>a;
		//node* p= createNode(a);
		insert2(root,a);
	}
	del(bst_search1(root,2));
	inorder(root);
	cout<<endl;
	node * p = bst_search2(root,2);
	node* q = NULL;
	if(p)
	q = successor(p);
	if(q)
		cout<<q->data<<endl;
	return 0;
}