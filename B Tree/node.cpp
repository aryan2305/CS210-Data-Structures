#include "node.h"
using namespace std;

#define MIN_DEGREE 3

node::node(){
	isLeaf=false;
	parent=NULL;
	numKeys=0;
	for (int i = 0; i < 2*MIN_DEGREE; ++i)
	{
		children[i]=NULL;
	}
}

bool node::isFull(){
	if(this->numKeys== (2*MIN_DEGREE)-1)
		return true;
	else
		return false;
}

void node::setParent(node* x){
	parent=x;
}

node* node::getParent(){
	return parent;
}

void node::setLeaf(bool value){
  isLeaf = value; 
}

bool node::getLeaf(){
  return isLeaf;
}

void node::setNumKeys(int value){
  numKeys = value;
}

int node::getNumKeys(){
  return numKeys;
}

int node::getKeyAtIndex(int i){
  return keys[i];
}

node* node::getChildAtIndex(int i){
  return children[i];
}

void node::setChildAtIndex(node* child, int i){
  children[i] = child;
}

void node::setKeyAtIndex(int key, int i){
  keys[i] = key;
}
