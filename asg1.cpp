#include <bits/stdc++.h>
using namespace std;
struct
{
    string name;
    int roll;
    float sgpa;
    
}s[15],temp,key;

void bubbleSort()
{
    for (int i = 0; i < 15; i++) 
    {
      for (int j = 0; j < 15 - i; j++) 
        {
            if (s[j].roll > s[j + 1].roll) 
            {
                temp=s[j];
                s[j]=s[j + 1];
                s[j + 1]=temp;
            }
        }
    }
}

void insertionSort()
{
    int i,j;
    for (i = 1; i < 15; i++)
    {
        key = s[i];
        j = i - 1;
        while (j >= 0 && s[j].name > key.name) 
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

void quickSort(int first,int last)
{
    int p,i,j;
    p=i=first;
    j=last;

    if(first<last)
    {
        while(i<j)
        {
            while(s[i].sgpa<=s[p].sgpa && i<last)
                i++;
            while(s[j].sgpa>s[p].sgpa)
                j--;
            if(i<j)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
        temp=s[p];
        s[p]=s[j];
        s[j]=temp;
        quickSort(first,j-1);
        quickSort(j+1,last);
    }
}

void display()
{
    for (int i=0;i<15;i++)
    {
        cout<<"Name : "<<s[i].name<<"\t Roll No. : "<<s[i].roll<<"\t SGPA : "<<s[i].sgpa<<endl;
    }
}

void displayOne(int i)
{
    cout<<"Name : "<<s[i].name<<"\t Roll No. : "<<s[i].roll<<"\t SGPA : "<<s[i].sgpa<<endl;
}

void displayFirstTen()
{
    for (int i=14;i>4;i--)
    {
        cout<<"Name : "<<s[i].name<<"\t Roll No. : "<<s[i].roll<<"\t SGPA : "<<s[i].sgpa<<endl;
    }
}

void linearSearch(float x)
{
    for (int i = 0; i < 15; i++)
        if (s[i].sgpa == x)
            displayOne(i);
}

void binarySearch(string x)
{
    int l=0,h=14;
    while (l <= h) 
    {
        int mid = l + (h - l) / 2;
 
        if (s[mid].name == x)
            displayOne(mid);
 
        if (s[mid].name < x)
            l = mid + 1;
 
        else
            h = mid - 1;
    }
}


int main()
{
    for (int i=0;i<15;i++)
    {
        cin>>s[i].name;
        cin>>s[i].roll;
        cin>>s[i].sgpa;
    }
    float sg;
    string nm;
    int ch;
    char cont='y';
    while(cont=='y')
    {
        cout<<"Enter your choice : \n 1 : List of students roll number wise \n 2 : List of students alphabetically \n 3 : First 10 toppers are \n 4 : Search students according to SGPA \n 5 : Search a particular student according to name \n";
        cin>>ch;
        switch(ch)
        {
            case 1 :cout<<"List of students roll number wise : "<<endl;
                    bubbleSort();
                    display();
                    cout<<endl;
                    break;
            case 2 :cout<<"List of students alphabetically : "<<endl;
                    insertionSort();
                    display();
                    cout<<endl;
                    break;
            case 3 :cout<<"First 10 toppers are : "<<endl;
                    quickSort(0,14);
                    displayFirstTen();
                    cout<<endl;
                    break;
            case 4 :cout<<"Enter the students SGPA you want to find \n";
                    cin>>sg;
                    linearSearch(sg);
                    cout<<endl;
                    break;
            case 5 :cout<<"Enter the students name whose information is to be displayed \n";
                    cin>>nm;
                    insertionSort();
                    binarySearch(nm);
                    cout<<endl;
                    break;
            default:cout<<"invalid input"<<endl;
                    break;
        }
        cout<<"Do you want to continue ? press y/n ";
        cin>>cont;
    }
}