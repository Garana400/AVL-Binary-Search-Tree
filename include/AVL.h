#ifndef AVL_H
#define AVL_H
#include <bits/stdc++.h>
using namespace std ;
class node
{
public :
    int key , hight ;
    node *right;
    node *left ;
    node (int pKey)
    {
        key = pKey ;
        hight = 1 ;
        left= right = NULL ;

    }
};
class AVL
{
    public:
        AVL();
        AVL (int data) ;
        node * rightRotate (node *curNode) ;
        node * leftRotate (node *curNode) ;
        int getBalance (node *curNode) ;
        int getHight (node *curNode ) ;
        node* Insert (node *curNode , int Data ) ;
        node* Delete (node*curnode , int Data) ;
        node* getRoot () ;
        bool Search (node *curNode , int value) ;
        void printInOrder(node* curNode) ;
        void printPreOrder (node* curNode) ;
        void printPostOrder (node *curNode) ;
        void setRoot (node * obj) ;
    private:
        node*root ;

};

#endif // AVL_H
