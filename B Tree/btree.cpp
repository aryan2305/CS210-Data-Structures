#include<bits/stdc++.h>
#include<string>
#include "node.h"
#include "btree.h"
using namespace std;
#define MIN_DEGREE 3 
// Tree initialization
btree::btree(){
  root = new node();
  root->setLeaf(true);
  root->setNumKeys(0);
}

tuple<node*, int> btree::search(node* subtree, int key){
  // Implementation based on CLRS
  int i = 0;
  // Find the right key position.
  while ( i < subtree->getNumKeys() & key > subtree->getKeyAtIndex(i)){
    i++;
  }
  // If key matches, return the result as a tuple.
  if (i < subtree->getNumKeys() & key == subtree->getKeyAtIndex(i)){
    return make_tuple(subtree, i);
  }
  else{
    // Key does not matches and is a leaf node, return NULL.
    if (subtree->getLeaf()){
      return make_tuple(static_cast<node*>(NULL), 0);
    }
    // Search recursively the correct subtree.
    else return search(subtree->getChildAtIndex(i), key);
  }
}

void btree::insert(btree* tree, int key){
  // Implementation based on CLRS
  node* root = tree->root;
  // If root is full, split it.
  if (root->getNumKeys() == (2 * MIN_DEGREE) - 1){
    node* s = new node();
    tree->root = s;
    s->setLeaf(false);
    s->setNumKeys(0);
    s->setChildAtIndex(root, 0);
    btree::splitChild(s, 0);
    btree::insertNonFull(s, key);
  }
  else{
    btree::insertNonFull(root, key);
  }
}

void btree::insertNonFull(node* x, int key){
  // Implementation based on CLRS
  cout << "Insert node full called on " << key << endl;
  int i = x->getNumKeys();
  // If the node is a leaf node, insert at the correct position.
  if (x->getLeaf()){
    while (i > 0 and key < x->getKeyAtIndex(i - 1)){
      x->setKeyAtIndex(x->getKeyAtIndex(i - 1), i);
      i--;
    }
    x->setKeyAtIndex(key, i);
    x->setNumKeys(x->getNumKeys() + 1);
  }
  else{
    // Is the node is not a leaf node, find the candidate child.
    while(i > 0 & key < x->getKeyAtIndex(i - 1)){
      i--;
    }
    i++;
    // If the child is full, split it.
    if (x->getChildAtIndex(i - 1)->getNumKeys() == (2 * MIN_DEGREE) - 1){
      btree::splitChild(x, i - 1);
      if (key > x->getKeyAtIndex(i - 1)){
        i++;
      }
    }
    btree::insertNonFull(x->getChildAtIndex(i - 1), key);
  }
}

void btree::splitChild(node* x, int i){
  // Implementation based on CLRS
  cout << "Splitting child at index " << i << endl;
  node* z = new node();
  node* y = x->getChildAtIndex(i);
  z->setLeaf(y->getLeaf());
  z->setNumKeys(MIN_DEGREE - 1);

  for (int j = 0; j < MIN_DEGREE - 1; j++){
    z->setKeyAtIndex(y->getKeyAtIndex(j + MIN_DEGREE), j);
  }

  if (!y->getLeaf()){
    for (int j = 0; j <= MIN_DEGREE; j++){
      z->setChildAtIndex(y->getChildAtIndex(j+MIN_DEGREE), j);
    }
  }
  y->setNumKeys(MIN_DEGREE - 1);
  for (int j = x->getNumKeys(); j >= i + 1; j--){
    x->setChildAtIndex(x->getChildAtIndex(j), j + 1);
  }
  x->setChildAtIndex(z, i + 1);
  for (int j = x->getNumKeys(); j > i; j--){
    x->setKeyAtIndex(x->getKeyAtIndex(j - 1), j);
  }
  x->setKeyAtIndex(y->getKeyAtIndex(MIN_DEGREE - 1), i);
  x->setNumKeys(x->getNumKeys() + 1);
}

void btree::postOrderTraversal(node* subtree, int depth){
  // Print the vertical tree for debugging.
  // The number of times '-' illustrate the depth of the node within the tree.
  // Please check the provided test case.
  if(subtree == NULL)
    return;
  int nodesPresent = subtree->getNumKeys();
  if (subtree->getLeaf()){
    for (int j = nodesPresent - 1; j >= 0; j--){
      cout <<  std::string(depth + 1, '-') << subtree->getKeyAtIndex(j) << endl;
    }
  }
  else{
    for (int j = nodesPresent; j > 0; j--){
      btree::postOrderTraversal(subtree->getChildAtIndex(j), depth + 1);
      cout <<  std::string(depth + 1, '-') << subtree->getKeyAtIndex(j - 1) << endl;
    }
    btree::postOrderTraversal(subtree->getChildAtIndex(0), depth + 1);
  }
}

void btree::insertBottomUp(btree* tree,int key){
  node* x = tree->root;
  
  int i;
  while(1){
    if(x->getLeaf())
      break;
    i = x->getNumKeys();
    while(i > 0 & key < x->getKeyAtIndex(i - 1)){
      i--;
    }
    x = x->getChildAtIndex(i);
  }

  node* child = NULL;
  while(1)
  {
    i = x->getNumKeys();
    while(i > 0 & key < x->getKeyAtIndex(i - 1)){
      i--;
    }

    if(!(x->isFull()))        //If the node is not full
    {
      int temp;
      node* temp2;
      if(i==x->getNumKeys())
      {
        temp = key;
        temp2 = child;
      }
      else
      {
        temp = x->getKeyAtIndex(x->getNumKeys()-1);
        for (int j = x->getNumKeys()-1; j >=i+1 ; --j)
        {
          x->setKeyAtIndex(x->getKeyAtIndex(j-1),j);
        }
        x->setKeyAtIndex(key,i);

        temp2= x->getChildAtIndex(x->getNumKeys());
        for (int j = x->getNumKeys(); j > i+1 ; --j)
        {
          x->setChildAtIndex(x->getChildAtIndex(j-1),j);
        }
        x->setChildAtIndex(child,i+1);

      }   

      x->setKeyAtIndex(temp,x->getNumKeys());
      x->setChildAtIndex(temp2,x->getNumKeys()+1);
      x->setNumKeys(x->getNumKeys()+1);
      break;
    }
    /*If the node is full*/
    else{
      int temp;
      node* temp2;
      if(i==x->getNumKeys())
      {
        temp = key;
        temp2 = child;
      }
      else
      {
        temp = x->getKeyAtIndex(x->getNumKeys()-1);
        for (int j = x->getNumKeys()-1; j >=i+1 ; --j)
        {
          x->setKeyAtIndex(x->getKeyAtIndex(j-1),j);
        }
        x->setKeyAtIndex(key,i);

        temp2= x->getChildAtIndex(x->getNumKeys());
        for (int j = x->getNumKeys(); j > i+1 ; --j)
        {
          x->setChildAtIndex(x->getChildAtIndex(j-1),j);
        }
        x->setChildAtIndex(child,i+1);

      }

      /*For distributing between siblings if simple bottom up insertion is required comment
       the below two line of if statement*/

      if(QuerySiblings(tree,temp,temp2,x))   //for key distribution
        break;

        node* child2 = new node();
        child=child2;
        child->setParent(x->getParent());
        child->setLeaf(x->getLeaf());

        int j;
        for (j = 0; j <MIN_DEGREE-1 ; ++j)
        {
          child->setKeyAtIndex(x->getKeyAtIndex(j+MIN_DEGREE),j);
        }        
        child->setKeyAtIndex(temp,j);
        child->setNumKeys(MIN_DEGREE);

        for (int j = 0; j <MIN_DEGREE ; ++j)
        {
          child->setChildAtIndex(x->getChildAtIndex(j+MIN_DEGREE),j);
        }
        child->setChildAtIndex(temp2,j);

        int s = x->getKeyAtIndex(MIN_DEGREE-1);
        x->setNumKeys(MIN_DEGREE-1);

        if(x==tree->root)
        {
          node* anod = new node();
          anod->setKeyAtIndex(s,0);
          anod->setNumKeys(1);
          anod->setChildAtIndex(x,0);
          x->setParent(anod);
          anod->setChildAtIndex(child,1);
          child->setParent(anod);
          anod->setLeaf(false);
          tree->root=anod;
          break;
        }
        x=x->getParent();
        key=s;
    }
  }

}

int btree::QuerySiblings(btree* tree, int extrakey, node* extraChild ,node* x){

  if(x==tree->root)
    return 0;
  node* parent = x->getParent();

  int i=parent->getNumKeys();
  while(i>=0)
  {
    if(parent->getChildAtIndex(i)==x)
      break;
    i--;
  }
  if(i+1<=parent->getNumKeys() && !(parent->getChildAtIndex(i+1)->isFull()))
  {
    node* rightSibling = parent->getChildAtIndex(i+1);
    int temp = parent->getKeyAtIndex(i);
    parent->setKeyAtIndex(extrakey,i);

    int j=rightSibling->getNumKeys();
    while(j>0)
    {
      rightSibling->setKeyAtIndex(rightSibling->getKeyAtIndex(j-1),j);
      j--;
    }
    rightSibling->setKeyAtIndex(temp,0);
    rightSibling->setNumKeys(rightSibling->getNumKeys()+1);

    j=rightSibling->getNumKeys();
    while(j>0)
    {
      rightSibling->setChildAtIndex(rightSibling->getChildAtIndex(j-1),j);
      j--;
    }
    rightSibling->setChildAtIndex(extraChild,0);
    return 1;
  }
  else if(i-1>=0 && !(parent->getChildAtIndex(i-1)->isFull()))
  {
    node* leftSibling = parent->getChildAtIndex(i-1);
    int temp= x->getKeyAtIndex(0);
    node* child = x->getChildAtIndex(0);
    int j=0;
    while(j<x->getNumKeys()-1)
    {
      x->setKeyAtIndex(x->getKeyAtIndex(j+1),j);
      x->setChildAtIndex(x->getChildAtIndex(j+1),j);
      j++;
    }
    x->setChildAtIndex(x->getChildAtIndex(j+1),j);
    x->setKeyAtIndex(extrakey,j);
    x->setChildAtIndex(extraChild,j+1);

    int temp2 = parent->getKeyAtIndex(i-1);
    parent->setKeyAtIndex(temp,i-1);
    leftSibling->setKeyAtIndex(temp2,leftSibling->getNumKeys());
    leftSibling->setChildAtIndex(child,leftSibling->getNumKeys()+1);
    leftSibling->setNumKeys(leftSibling->getNumKeys()+1);     
    return 1;
  }
  
  return 0;
}
