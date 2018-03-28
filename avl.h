#ifndef AVL_H
#define AVL_H
#include <bits/stdc++.h>
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>
using namespace std ;

class node
{
public :
    int key , hight ;
    node *right;
    node *left ;
    node *p ;
    node ()
    {
        hight = 1 ;
        left = right = NULL ;
    }
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
       void deleteNode(int val);
       node* getRoot () ;
       bool Search (node *curNode , int value) ;
       void printInOrder(node* curNode) ;
       void printPreOrder (node* curNode) ;
       void printPostOrder (node *curNode) ;
       void setRoot (node * obj) ;
       node * minValue (node *curNode) ;
       //*** ///////
       void init(QGraphicsScene* scene, QGraphicsView* view);
       int countNodes();
       int countLevels();
       int countLeftNodes();
       void show();
       void insert(int a);
       bool findElem(int val);
       void preorderWalk();
       void postorderWalk();
       void inorderWalk();
   private:
       node*root ;
       QGraphicsScene* _scene;
       QGraphicsView* _view;
       int countNodes(node* p);
       int countLevels(node* p);
       int countLeftNodes(node *p);
       node* findSuccessor(int val);
       QByteArray _prepareGraph();
       void _graphWalk(node* p,  QTextStream* stream);
       void preorderWalk(node* p);
       void postorderWalk(node* p);
       void inorderWalk(node* p);

};

#endif // AVL_H
