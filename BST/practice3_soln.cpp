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
	return nd;
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
int searchIndex(int arr[],int start, int end, int key)
{
	for (int i = start; i <= end; ++i)
	{
		if(arr[i]==key)
			return i;
	}
}
node* makeBinary(int in[], int pre[], int start, int end)
{
	static int preIndex=0;

	if(start > end)
		return NULL;

	node * Newnode = createNode(pre[preIndex++]);

	if(start==end)
		return Newnode;

	int index = searchIndex(in,start,end,Newnode->data);

	Newnode->left= makeBinary(in,pre,start,index-1);
	Newnode->right=makeBinary(in,pre,index+1,end);

	return Newnode;
}

node* makeBinary2(int in[], int post[], int start, int end,int* postIndex)
{
	if(start > end)
		return NULL;

	node * Newnode = createNode(post[*postIndex]);
	(*postIndex)--;

	if(start==end)
		return Newnode;

	int ind = searchIndex(in,start,end,Newnode->data);

	Newnode->right=makeBinary2(in,post,ind+1,end,postIndex);
	Newnode->left= makeBinary2(in,post,start,ind-1,postIndex);

	return Newnode;
}

int main()
{
	int n;
	cin>>n;
	int inordr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>inordr[i];
	}

	int preorder[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>preorder[i];
	}

	int postorder[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>postorder[i];
	}
	int index=n-1;
	node* root1 = makeBinary(inordr,preorder,0,n-1);
	node* root2 = makeBinary2(inordr,postorder,0,n-1,&index);
	inorder(root2);
	cout<<endl;
	return 0;
}