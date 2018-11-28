#include "node.h"

using namespace std;

node::node(int keyValue)
{
    parent=NULL;
    left=NULL;
    right=NULL;
    lnum=0;
    rnum=0;
    key=keyValue;
    lheight=0;
    rheight=0;

}

node::~node()
{
    //dtor
}

int node::getKey(){
  return key;
}

node* node::getParent(){
  return parent;
}

node* node::getLeft(){
  return left;
}

node* node::getRight(){
  return right;
}

bool node::setParent(node* parentNode){
  parent = parentNode;
  return true;
}

bool node::setLeft(node* leftNode){
  left = leftNode;
  return true;
}

bool node::setRight(node* rightNode){
  right = rightNode;
  return true;
}

bool node::setLHeight(int height){
  lheight = height;
  return true;
}

bool node::setRHeight(int height){
  rheight = height;
  return true;
}

int node::getLHeight(){
  return lheight;
}

int node::getRHeight(){
  return rheight;
}

bool node::setlnum(int num){
  lnum = num;
  return true;
}

bool node::setrnum(int num){
  rnum = num;
  return true;
}

int node::getlnum(){
  return lnum;
}

int node::getrnum(){
  return rnum;
}

