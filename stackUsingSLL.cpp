#include<iostream>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
int top=-1,n;
node* PUSH(node *head)
{
    if(top!=(n-1))
    {
        char data;
        cout<<"Enter character to be pushed : ";
        cin>>data;
        node *temp=new node();
        temp->data=data;
        temp->next=NULL;
        node *ptr=head;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
        top++;
    }
    else
    {
        cout<<"Cannot PUSH, stack overflowed \n";
    }
    return head;
}

node* POP(node *head)
{
    if(top!=-1)
    {
        if(head==NULL)
        {
            cout<<"Linked list is already empty \n";
        }
        else if(head->next==NULL)
        {
            free(head);
            head=NULL;
            cout<<"Linked list is now empty \n";
        }
        else
        {
            node *ptr=head;
            while(ptr->next->next!=NULL)
            {
                ptr=ptr->next;
            }
            delete(ptr->next);
            ptr->next=NULL;
        }
        top--;
    }
    else
    {
        cout<<"Cannot POP ,stack underflowed \n";
    }
    return head;
}

void display(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main()
{
    int ch;
    char data,cont='y';
    node *head=NULL;
    cout<<"Enter the length of the stack : ";
    cin>>n;
    while(cont=='y')
    {
        cout<<"what operation do you want to perform ? : \n press 1 for PUSH \n press 2 for POP \n";
        cin>>ch;
        switch(ch)
        {
            case 1 :head=PUSH(head);
                    break;
            case 2: head=POP(head);
                    break;
            default: cout<<"Invalid input ";
                    break;
        }
        cout<<"Do you want to continue (y/n)? : ";
        cin>>cont;
    }
    display(head);

}