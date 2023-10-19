#include<iostream>
#include<string>
using namespace std;
struct node
{
    char data;
    struct node *next;
};

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
    node *stack=NULL;

    int ch;
    cout<<"Enter 1 for postfix \n Enter 2 for prefix : \n";
    cin>>ch;
    switch(ch)
    {
        case 1: while(i!=(n-1))
                {
                    if(infix[i]!='^'||'$'||'*'||'/'||'%'||'+'||'-'||'('||')')
                    {
                        postfix.append(infix[i]);
                    }
                    else
                    {
                        if(stack==NULL)
                        {
                            top=PUSH(stack,infix[i],top,n);
                        }
                        else if(infix[i]=='(')
                        {
                            top=PUSH(stack,infix[i],top,n);
                        }
                        else if(infix[i]==')')
                        {
                            while(stack->data!='(')
                            {
                                postfix.append(stack->data);
                                top=POP(stack,infix[i],top,n);
                            }
                            top=POP(stack,infix[i],top,n);
                        }
                        
                        
                    }
                    i++;
                }
                break;
        case 2:
    }
    
    display(stack);

}