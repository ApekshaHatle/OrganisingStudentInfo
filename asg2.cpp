#include<iostream>
#include<string>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
int top=-1,n;

int PUSH(node *&head,char data,int top,int n)
{
    if(top!=(n-1))
    {
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
            temp->next=head;
            head=temp;
        }
        top++;
    }
    else
    {
        cout<<"Cannot PUSH, stack overflowed \n";
    }
    return top;
}

int POP(node *&head,int top,int n)
{
    if(top!=-1)
    {
        if(head==NULL)
        {
            cout<<"Linked list is empty \n";
        }
        else
        {
            node *current=head;
            head=head->next;
            delete(current);        //free that original head
            current=NULL;
        }
        top--;
    }
    else
    {
        cout<<"Cannot POP ,stack underflowed \n";
    }
    return top;
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
    string infix,postfix="",prefix="";
    cout<<"Enter the infix :\n";
    cin>>infix;
    int top=-1,n=infix.size();
    cout<<n;
    node *stack=NULL;
    top=PUSH(stack,'e',top,n);
    cout<<top<<endl;
    top=PUSH(stack,'i',top,n);
    cout<<top<<endl;
    top=PUSH(stack,'o',top,n);
    cout<<top<<endl;
    top=POP(stack,top,n);
    cout<<top<<endl;
    // int ch;
    // cout<<"Enter 1 for postfix \n Enter 2 for prefix : \n";
    // cin>>ch;
    // switch(ch)
    // {
    //     case 1: while(i!=(n-1))
    //             {
    //                 if(infix[i]!='^'||'$'||'*'||'/'||'%'||'+'||'-'||'('||')')
    //                 {
    //                     postfix.append(infix[i]);
    //                 }
    //                 else
    //                 {
    //                     if(stack==NULL)
    //                     {
    //                         postfix.append(infix[i]);
    //                     }
    //                     else if(infix[i]=='(')
    //                     {
    //                         postfix.append(infix[i]);
    //                     }
    //                     else if(infix[i]==')')
    //                     {
    //                         if()
    //                     }
                        
    //                 }
    //                 i++;
    //             }
    //             break;
    //     case 2:
    // }
    
    display(stack);

}