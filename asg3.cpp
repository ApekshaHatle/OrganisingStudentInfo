#include<iostream>
using namespace std;
class CircularQueue
{
	public:
		int arr[5];
		int front=-1;
		int rear=-1;
		void Enqueue(int x);
		void Dequeue();
		void Display();
		bool isFull()
		{
			if((rear+1)%5==front)
			{
				return true;
			}
			return false;
		}
		bool isEmpty()
		{
			if(rear==-1 && front==-1)
			{
				return true;
			}
			return false;
		}
};

void CircularQueue :: Enqueue(int x)
{
	if(isFull())
	{
		cout<<"queue is full \n";
	}
	else
	{
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
			rear=(rear+1)%5;
		}
		arr[rear]=x;
		cout<<"inserted "<<x<<endl;
	}
}

void CircularQueue :: Dequeue()
{
	if(isEmpty())
	{
		cout<<"queue is empty \n";
	}
	else
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%5;
		}
		cout<<"deleted "<<endl;
	}
}


void CircularQueue :: Display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<arr[i]<<"\t";
	}
}

int main()
{
	CircularQueue cq;
	char cont='y';
	int ch,data;
	while(cont=='y')
	{
		cout<<"Enter your choice \n";
		cout<<"Press 1 to Enqueue data in Queue \n";
		cout<<"Press 2 to Dequeue data in Queue \n";
		cout<<"Press 3 to Display \n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter data you want to enqueue : ";
				cin>>data;
				cq.Enqueue(data);
				break;
			case 2: cout<<"Dequeueing one element \n";
				cq.Dequeue();
				break;
			case 3: cout<<"The queue is : \n";
				cq.Display();
				break;
			default:cout<<"Invalid Input \n";
				break;
		}
		cout<<"Do you want to continue(y/n) ? : ";
		cin>>cont;

	}
	
}
