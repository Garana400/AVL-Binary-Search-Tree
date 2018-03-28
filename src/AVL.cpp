#include "AVL.h"
#include <bits/stdc++.h>
using namespace std ;

AVL::AVL()
{
    root  = NULL ;
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
    node *left = curNode->left ;
    node *rightGrand = left->right ;

    left->right = curNode ;
    curNode->left = rightGrand ;

    curNode->hight = max ( getHight(curNode->left), getHight(curNode->right)) +1 ;
    left->hight = max (getHight(left->left) , getHight(left->right)) +1 ;

    return left ;
}

node* AVL :: leftRotate (node *curNode)
{
    node *right = curNode->right ;
    node *leftGrand = right->left ;

    right->left = curNode ;
    curNode ->right = leftGrand ;

    curNode->hight = max (getHight(curNode->left) , getHight(curNode->right)) +1 ;
    right->hight = max (getHight(right->left), getHight(right->right)) +1 ;

    return right ;

}

node* AVL :: Insert(node *curNode , int Data)
{

    if (curNode == NULL)
        return new node(Data) ;

    if (Data == curNode->key)
        return root ;


    if (curNode->key > Data)
    {

        curNode->left = Insert(curNode->left , Data) ;

    }else
    {
        curNode->right = Insert(curNode->right , Data) ;

    }

    curNode->hight = max (getHight(curNode->left) , getHight(curNode->right)) +1 ;

    int balance = getBalance(root) ;
    cout << balance << endl ;

      /** 4 cases **/

    if (balance > 1 && Data < curNode->left->key)
        return rightRotate(curNode) ;
    else if (balance < -1 && Data > (curNode->right->key))
        return leftRotate(curNode) ;

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

node* AVL :: Delete (node* curNode , int data)
{
    if (curNode == NULL)
      {

      }
    if (curNode->key > data)
        curNode->left = Delete(curNode->left , data) ;
    else if (data > curNode->key)
    {
        curNode->right = Delete(curNode->right , data) ;
    }

    else if (curNode->key == data)
    {
        if (curNode->left == NULL)
        {
            node* temp = curNode ;
            curNode = curNode->right ;
            delete temp ;
        }else if (curNode->right == NULL)
        {
            node * temp = curNode ;
            curNode = curNode->left ;
            delete temp ;
        }else
        {
            node *rightMostChild = curNode->left ;
            while (rightMostChild->right !=NULL)
                rightMostChild = rightMostChild->right ;
            curNode->key = rightMostChild->key ;
            curNode->left = Delete(curNode->left , rightMostChild->key) ;
        }

    }

    if (curNode == NULL)
        return NULL ;
    /** 4 cases **/
    curNode->hight = max (getHight(curNode->left) , getHight(curNode->right) ) +1 ;
    int balance = getBalance(curNode) ;

    if (balance >1 && getBalance(curNode->left)>= 0 )
    {
        return rightRotate(curNode) ;
    }else if (balance <-1 && getBalance(curNode->right)<= 0)
    {
        return rightRotate(curNode) ;
    }else if (balance >1 && getBalance(curNode->left) <0)
    {
        curNode->left = leftRotate(curNode->left) ;
        return rightRotate(curNode) ;
    }else if (balance <-1 && getBalance(curNode->right) >0)
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
        cout << "Not Found\n" ;
        return false ;
    }
    if (curNode->key == value)
        return true ;
    if (curNode->key > value)
        Search(curNode->left , value) ;
    else
    {
        Search(curNode->right , value) ;
    }
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
