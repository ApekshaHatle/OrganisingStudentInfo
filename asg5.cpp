#include<iostream>
using namespace std;

struct node
{
    struct node *right;
    struct node *left;
    int data; 
}

class BST
{
    public:
        
        node *current=new node;
        void Create(int data);
        void Insert(int data);
        void Search(int key);
        void Delete(int key);
        void Display();
}

void BST :: Create(int data, node *&N)
{
    if(root=NULL;)
    {
        node *root=new node;
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        node N=new node;
        N->data=data;
        N->left=NULL;
        N->right=NULL;
    }  
}

void BST :: Insert(int data)
{
    
}

void BST :: Search(int key)
{

}

void BST :: Delete(int key)
{

}

void BST :: Display()
{

}
int main()
{

}