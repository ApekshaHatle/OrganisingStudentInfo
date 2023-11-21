#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct tree
{
	char data;
	struct tree *rightChild;
	struct tree *leftChild;
};
class ExpTree
{
	public:
		tree* ETfromPostfix(string postfix);
		tree* ETfromPrefix(string prefix);
		void inOrder(tree *root);
		void preOrder(tree *root);
		void postOrder(tree *root);
};

tree* ExpTree :: ETfromPostfix(string postfix)
{
	stack<struct tree*> stack;
	int n=postfix.size();
	for(int i=0;i<n;i++)
	{
		tree *current=new tree();
		current->data=postfix[i];
		current->rightChild=NULL;
		current->leftChild=NULL;
		if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^' || postfix[i] == '%')
		{
			current->rightChild=stack.top();     //1st popped
			stack.pop();
			current->leftChild=stack.top();	     //2nd popped
			stack.pop();
			stack.push(current);		
		}
		else
		{
			stack.push(current);
		}	
	}
	return stack.top();	
}

tree* ExpTree :: ETfromPrefix(string prefix)
{
	stack<struct tree*> stack;
	int n=prefix.size();
	for(int i=n-1;i>=0;i--)
	{
		tree *current=new tree();
		current->data=prefix[i];
		current->rightChild=NULL;
		current->leftChild=NULL;
		if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^' || prefix[i] == '%')
		{
			current->leftChild=stack.top();     //1st popped
			stack.pop();
			current->rightChild=stack.top();	//2nd popped
			stack.pop();
			stack.push(current);
					
		}
		else
		{
			stack.push(current);
		}	
	}
	return stack.top();	
}

void ExpTree :: inOrder(tree *root)
{
	if(root!=NULL)
	{
		inOrder(root->leftChild);
		cout<<root->data<<" ";
		inOrder(root->rightChild);
	}
}

void ExpTree :: preOrder(tree *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}

void ExpTree :: postOrder(tree *root)
{
	if(root!=NULL)
	{
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		cout<<root->data<<" ";
	}
}

int main()
{
	ExpTree ET;
	int ch;
	string s;
	char cont='y';
	
	while(cont=='y')
	{
		cout<<"Enter 1 to construct Expression tree from postfix expression\n Enter 2 to construct Expression tree from prefix expression\n";
		cin>>ch;
		switch(ch)
		{
			case 1:	
				{
					cout<<"Enter postfix expression";
					cin>>s;
					tree *root=ET.ETfromPostfix(s);
					int chPost;
					char contPost='y';
					while(contPost=='y')
					{
						cout<<"Enter 1 for in-order traversal \nEnter 2 for pre-order traversal \nEnter 3 for post-order traversal \n";
						cin>>chPost;
						switch(chPost)
						{
							case 1:	cout<<"In-order traversal : \n";
									ET.inOrder(root);
									break;
							case 2:	cout<<"In-order traversal : \n";
									ET.preOrder(root);
									break;
							case 3:	cout<<"In-order traversal : \n";
									ET.postOrder(root);
									break;
							default:cout<<"Invalid input \n";
									break;
						}
						cout<<"Do you want to continue(y/n) ? ";
						cin>>contPost;
					}
					break;
				}
			case 2:	
				{	
					cout<<"Enter prefix expression";
					cin>>s;
					tree *root=ET.ETfromPrefix(s);
					int chPre;
					char contPre='y';
					
					while(contPre=='y')
					{
						cout<<"Enter 1 for in-order traversal \nEnter 2 for pre-order traversal \nEnter 3 for post-order traversal \n";
						cin>>chPre;
						switch(chPre)
						{
							case 1:	cout<<"In-order traversal : \n";
									ET.inOrder(root);
									break;
							case 2:	cout<<"In-order traversal : \n";
									ET.preOrder(root);
									break;
							case 3:	cout<<"In-order traversal : \n";
									ET.postOrder(root);
									break;
							default:cout<<"Invalid input \n";
									break;				
						}
						cout<<"Do you want to continue(y/n) ? ";
						cin>>contPre;
					}
					break;
				}
					default:cout<<"invalid input \n";
						break;
			}
		cout<<"Do you want to continue(y/n) ? ";
		cin>>cont;
	}
}
