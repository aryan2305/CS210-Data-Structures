#include<bits/stdc++.h>
using namespace std;
typedef struct _node{
	int data;
	bool rthread;
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
	nd->rthread=false;
	return nd;
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

void inorder(node* root)
{
	node* p = root;
	node* temp;
	while(p!=NULL)
	{
		if(p->left)
		{
			temp=p->left;
			while(temp->right!=NULL && temp->right!=p)
				temp=temp->right;
			if(temp->right==NULL)
				{
					temp->right=p;
					temp->rthread=true;
					p=p->left;
				}
			else
				{
					temp->right=NULL;
					temp->rthread=false;
					if(p->rthread)
						cout<<p->data<<"T ";
					else
						cout<<p->data<<" ";
					p=p->right;
				}
		}
		else
		{
			if(p->rthread)
				cout<<p->data<<"T ";
			else
				cout<<p->data<<" ";
			p=p->right;
		}
	}
}

void preorder(node* root)
{
	node* p = root;
	node* temp;
	while(p!=NULL)
	{
		
		if(p->left)
		{			
			temp=p->left;
			while(temp->right!=NULL && temp->right!=p)
				temp=temp->right;
			if(temp->right==NULL)
				{
					cout<<p->data<<" ";
					temp->right=p;
					p=p->left;
				}
			else
				{
					temp->right=NULL;
					p=p->right;
				}
		}
		else
		{
			cout<<p->data<<" ";
			p=p->right;
		}
	}
}

void postorder(node* root)
{
	node* dummy = createNode(0);
	dummy->left = root;
	node *p= dummy;
	node* pred;
	node *first,*middle,*last;
	while(p!=NULL)
	{
		
		if(p->left)
		{			
			pred=p->left;
			while(pred->right!=NULL && pred->right!=p)
				pred=pred->right;
			if(pred->right==NULL)
				{
					pred->right=p;
					p=p->left;
				}
			else
				{
					first=p;
					middle=p->left;
					while(middle!=p)
					{
						last=middle->right;
						middle->right = first;
						first =middle;
						middle=last;
					}

					first=p;
					middle=pred;
					while(middle!=p)
					{
						cout<<middle->data<<" ";
						last = middle->right;
						middle->right = first;
						first=middle;
						middle=last;
					}
					pred->right=NULL;
					p=p->right;
				}
		}
		else
		{
			p=p->right;
		}
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
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	return 0;
}