#ifndef AVL_H
#define AVL_H

#include "node.h"

using namespace std;

class avl
{
    public:
        avl();
        int insertNode(node* newNode, node* headNode);
        bool treeInsertNode(node* newNode);
        node* deleteNode(node* victimNode);
        node* searchKey(int, node*);
        node* treeSearchKey(int);
        void inorderTraversal(node* headNode);
        void preorderTraversal(node* headNode);
        void treeInorderTraversal();
        void rebalance(node* n);
        int updateHeights(node *n);
        int updateNodeNumbers(node *n);
        node* rotateRight(node* n);
        node* rotateLeft(node* n);
        node* rotateRightThenLeft(node* n);
        node* rotateLeftThenRight(node* n);
        node* head;

        virtual ~avl();
    protected:
    private:
        

};

#endif // AVL_H

