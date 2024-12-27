#include<iostream>
using namespace std;

void bubbleSort(int a[])
{
    int rounds=0;
    for(int i=0; i<5; i++)
    {
        rounds++;
        for(int j=0; j<(5-i-1); j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<"No of rounds in normal Bubble Sort: "<<rounds<<endl;

}

void optimizedbubblesort(int a[])
{
    int rounds=0;
    for(int i=0; i<5; i++)
    {
        rounds++;
        int flag = false;
        for(int j=0; j<(5-i-1); j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag==false)
        {
            break;
        }
    }
    cout<<"No of rounds in Optimized Bubble Sort : "<<rounds<<endl;
}

int main()
{
    int myarray[5];
    cout<<"Enter 5 integers in any order: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>myarray[i];
    }

    cout<<"Before Sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<myarray[i]<<" ";
    }
    cout<<endl;
    bubbleSort(myarray);
    optimizedbubblesort(myarray);

    cout<<endl<<"After Sorting: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<myarray[i]<<" ";
    }

    return 0;
}
