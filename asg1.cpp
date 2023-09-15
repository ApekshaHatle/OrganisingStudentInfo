#include <bits/stdc++.h>
using namespace std;
struct
{
    string name;
    int roll;
    float sgpa;
    
}s[5],temp,key;

void bubbleSort()
{
    for (int i = 0; i < 5; i++) 
    {
      for (int j = 0; j < 5 - i; j++) 
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
    for (i = 1; i < 5; i++)
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

void display()
{
    for (int i=0;i<5;i++)
    {
        cout<<"Name : "<<s[i].name<<endl;
        cout<<"Roll No. : "<<s[i].roll<<endl;
        cout<<"SGPA : "<<s[i].sgpa<<endl;
    }
}

void displayOne(int i)
{
    cout<<"Name : "<<s[i].name<<endl;
    cout<<"Roll No. : "<<s[i].roll<<endl;
    cout<<"SGPA : "<<s[i].sgpa<<endl;
}

void linearSearch(float x)
{
    for (int i = 0; i < 5; i++)
        if (s[i].sgpa == x)
            displayOne(i);
}

void binarySearch(string x)
{
    int mid=2,l=0,h=4;
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
    for (int i=0;i<5;i++)
    {
        cin>>s[i].name;
        cin>>s[i].roll;
        cin>>s[i].sgpa;
    }
    float sg;
    string nm;
    cout<<"List of students roll number wise : "<<endl;
    bubbleSort();
    display();
    cout<<endl;
    cout<<"List of students alphabetically : "<<endl;
    insertionSort();
    display();
    cout<<endl;
    cout<<"Enter the students SGPA you want to find \n";
    cin>>sg;
    linearSearch(sg);
    cout<<endl;
    cout<<"Enter the students name whose information is to be displayed \n";
    cin>>nm;
    insertionSort();
    binarySearch(nm);
}