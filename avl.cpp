#include "avl.h"
#include <bits/stdc++.h>
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>
using namespace std ;

AVL::AVL()
{
    root  = new node() ;
}

AVL :: AVL (int Data)
{
    root= new node(Data) ;
}

int AVL :: getHight (node *curNode)
{
    if(curNode == NULL)
        return 0 ;
    return curNode->hight ;
}

int AVL :: getBalance (node * curNode)
{
    if (curNode == NULL)
        return 0 ;
    return getHight(curNode->left) - getHight(curNode->right)  ;
}

node* AVL :: getRoot ()
{
    return root ;
}
node* AVL :: rightRotate (node *curNode)
{
    node *left = curNode->left ; //5
    node *rightGrand = left->right ;// null

    left->right = curNode ; //

    if (curNode->left !=NULL)
    {

        curNode->left = rightGrand ;
    }


    curNode->hight = max ( getHight(curNode->left), getHight(curNode->right)) +1 ;
    left->hight = max (getHight(left->left) , getHight(left->right)) +1 ;

    return left ;
}

node* AVL :: leftRotate (node *curNode)
{
    node *right = curNode->right ;
    node *leftGrand = right->left ;

    right->left = curNode ;

    if (curNode->right!= NULL)
    {

        curNode ->right = leftGrand ;
    }


    curNode->hight = max (getHight(curNode->left) , getHight(curNode->right)) +1;
    right->hight = max (getHight(right->left), getHight(right->right)) +1 ;

    return right ;

}

node* AVL :: Insert(node *curNode , int Data)
{

    if (curNode == NULL)
        return new node(Data) ;

    if (curNode->key > Data)
    {

        curNode->left = Insert(curNode->left , Data) ;

    }else if (curNode->key < Data)
    {
        curNode->right = Insert(curNode->right , Data) ;

    }

    curNode->hight = max (getHight(curNode->left) , getHight(curNode->right)) +1 ;

    int balance = getBalance(curNode) ;


      /** 4 cases **/

    if (balance > 1 && Data < curNode->left->key)
    {

        return rightRotate(curNode) ;
    }
    else if (balance < -1 && Data > (curNode->right->key))
    {

        return leftRotate(curNode) ;
    }
    else if (balance >1 &&  Data > curNode->left->key)
    {

        curNode->left = leftRotate(curNode->left) ;
        return rightRotate(curNode) ;
    }
    else if (balance <-1 && Data < curNode->right->key)
    {

        curNode->right = rightRotate(curNode->right) ;
        return leftRotate(curNode) ;
    }

    return curNode ;
}


node* AVL :: minValue (node *curNode)
{
    node *temp = curNode;
    while (temp->left != NULL)
        temp = temp->left ;
    return temp ;
}
node* AVL :: Delete (node* curNode , int data)
{
    if (curNode == NULL)
    {
        return curNode;
    }
    if (curNode->key > data)
        curNode->left = Delete(curNode->left , data) ;
    else if (data > curNode->key)
        curNode->right = Delete(curNode->right , data) ;
    else
    {

        if ( (curNode->left == NULL) || (curNode->right == NULL) )
        {
            node * temp = curNode->left ? curNode->left :
                                                    curNode->right ;
            if (temp == NULL )
            {
                temp = curNode ;
                curNode = NULL ;
            }else
                *curNode = *temp ;
             delete temp ;
        }else
        {
            node * temp = minValue(curNode->right) ;
            curNode->key = temp->key ;
            curNode->right = Delete(curNode->right , temp->key) ;

        }

    }

    if (curNode == NULL)
        return curNode ;
    /** 4 cases **/
    curNode->hight = max (getHight(curNode->left) , getHight(curNode->right) ) +1 ;
    int balance = getBalance(curNode) ;

    if (balance >1 && getBalance(curNode->left)>= 0 )
    {
        return rightRotate(curNode) ;
    }
    if (balance <-1 && getBalance(curNode->right)<= 0)
    {
        return leftRotate(curNode) ;
    }
     if (balance >1 && getBalance(curNode->left) <0)
    {
        curNode->left = leftRotate(curNode->left) ;
        return rightRotate(curNode) ;
    }
    if(balance <-1 && getBalance(curNode->right) >0)
    {
        curNode->right = rightRotate(curNode->right) ;
        return leftRotate(curNode) ;
    }

    return curNode ;
}

bool AVL :: Search (node *curNode , int value)
{
    if (curNode == NULL)
    {
        return false ;
    }
    if (curNode->key == value)
        return true ;
    if (curNode->key > value)
        return Search(curNode->left , value) ;
    else
        return Search(curNode->right , value) ;

    return false ;
}


void AVL :: printInOrder (node *curNode)
{
    if (curNode == NULL)
        return ;
    printInOrder(curNode->left) ;
    cout << curNode->key <<  " " ;
    printInOrder(curNode->right) ;
}

void AVL :: setRoot (node *obj)
{
    root = obj ;
}

void AVL :: insert (int a )
{
    this->root = this->Insert(this->root, a) ;
}


void AVL :: deleteNode (int val)
{
    this->root = Delete(this->root , val) ;
}

bool AVL :: findElem(int val)
{
    return this->Search(this->root , val) ;
}

//****************************************************************//
void AVL::init(QGraphicsScene* scene, QGraphicsView* view){
    this->root = NULL ;
    this->_scene = scene;
    this->_view = view;
}
int AVL::countLevels(node* p){
        int h1 = 0, h2 = 0;

        if(p == NULL) return 0;

        if(p->left){
            h1 = countLevels(p->left);
        }

        if(p->right){
            h2 = countLevels(p->right);
        }

        return(max(h1,h2)+1);
}

int AVL::countLevels(){
    return this->countLevels(this->root);
}

int AVL::countNodes(node* p){
      if(p == NULL){
            return 0;
      }else{
            return (countNodes(p->left) + countNodes(p->right)+1);
      }
}

int AVL::countNodes(){
    return this->countNodes(this->root);
}

int AVL::countLeftNodes(node* p) {
    if(p == NULL){
          return 0;
    }else{
        return (countLeftNodes(p->left) + countLeftNodes(p->right)) + (p->left != NULL && p->right == NULL)? 1 : 0;
    }
}

int AVL::countLeftNodes(){
    return this->countLeftNodes(this->root);
}

void AVL::_graphWalk(node* p, QTextStream *stream) {
    if (p != NULL){
            *stream << "\t\t" << "n" << p->key << "[label=\"" << p->key <<"\"];" << endl;

        if(p->left != NULL){
            *stream << "\t\tn" << p->key << "--" << "n" << p->left->key << ";" << endl;
            this->_graphWalk(p->left, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "leftNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "leftNull" << endl;
        }

        if(p->right != NULL){
            *stream << "\t\tn" << p->key << "--" << "n" << p->right->key << ";" << endl;
            this->_graphWalk(p->right, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "rightNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "rightNull" << endl;
        }
    }
}




void AVL::preorderWalk(node* p) {
    if (p != NULL) {
       cout << p->key << " ";
       this->preorderWalk(p->left);
       this->preorderWalk(p->right);
    }
}

void AVL::preorderWalk(){
    cout << "Preorder walk: ";
    this->preorderWalk(this->root);
    cout << endl;
}

void AVL::postorderWalk(node* p) {
        if (p != NULL) {
           this->postorderWalk(p->left);
           this->postorderWalk(p->right);
           cout << p->key << " ";
        }
}

void AVL::postorderWalk(){
    cout << "Postorder walk: ";
    this->postorderWalk(this->root);
    cout << endl;
}

void AVL::inorderWalk(node* p){
        if (p != NULL) {
           this->inorderWalk(p->left);
           cout << p->key << " ";
           this->inorderWalk(p->right);
        }
}

void AVL::inorderWalk(){
    cout << "Inorder walk: ";
    this->inorderWalk(this->root);
    cout << endl;
}

QByteArray AVL::_prepareGraph(){
    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;
    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;
    stream << "\tsubgraph cluster17{" << endl;

    this->_graphWalk(this->root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return a;
}

void AVL::show(){
    QProcess* p = new QProcess();
    QByteArray a = this->_prepareGraph();

    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();

    while(p->waitForReadyRead(100)){
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);
    this->_scene->clear();
    this->_scene->addPixmap(pixmap);
    this->_view->show();
}
