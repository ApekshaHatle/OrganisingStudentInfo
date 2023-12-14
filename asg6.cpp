#include<iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    int lbit;
    int rbit;
};

node *root = NULL; 
node *head=new node;
void insert(node *root, node *temp)
{
    // if(root==NULL)
    // {return;}
        if(temp->data<root->data)
        {
            if(root->lbit==0)
            {
                temp->left=root->left;
                temp->right=root;
                root->left=temp;
                root->lbit=1;
            }
            else
            {
                insert(root->left,temp);
            }
        }

        else if(temp->data>root->data)
        {
            if(root->rbit==0)
            {
                temp->right=root->right;
                temp->left=root;
                root->right=temp;
                root->rbit=1;
            }
            else
            {
                insert(root->right,temp);
            }
            
        }

}

void create()
{
    char ch='y';
    do{
        int data;
        cout<<"Enter element : ";
        node *temp=new node;
        cin>>data;
        temp->data=data;
        temp->right=NULL;
        temp->left=NULL;
        temp->lbit=0;
        temp->rbit=0;

        if(root==NULL)
        {
            root=temp;
            head->data=999;         //can be anything you want
            head->right=head;
            head->left=root;
            head->lbit=1;
            head->rbit=1;
            root->right=head;
            root->left=head;
            cout<<"you want to continue (y/n)? : ";
            cin>>ch;
        }
        else
        {
            insert(root,temp);
            cout<<"you want to continue (y/n)? : ";
            cin>>ch;
        }

    }while(ch=='y');
}

void inorder() {
    node *t=head->left;

    do{
    while(t->lbit!=0)
    {
        t=t->left;
    }
    cout<<t->data<<" ";

    while(t->rbit==0)
    {
        t=t->right;
        if(t==head)
            return;
        cout<<t->data<<" ";
    }
        t=t->right;
    }while(t!=head);

}

void preorder()
{
    node *t=head->left;

    do{
        while(t->lbit!=0)
        {
            cout<<t->data<<" ";
            t=t->left;
        }
        cout<<t->data<<" ";
        while(t->rbit==0)
        {
            t=t->right;
            if(t==head)
                return;
        }
        t=t->right;
    }while(t!=head);
}
int main() {
    int data;
    create();
    cout << "Inorder traversal: "<<endl;
    inorder();
    cout <<endl<< "Preorder traversal: "<<endl;
    preorder();

    return 0;
}