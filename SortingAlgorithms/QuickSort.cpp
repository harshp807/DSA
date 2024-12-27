#include<iostream>
using namespace std;

//quick sort sorting alogorithm


int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;
    
    for(int i=s; i<e;i++)
    {
        if(arr[i]<pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if(s<e)
    {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, (p-1)); //recursive QS call for left partition
        QuickSort(arr, (p+1), e); //recursive QS call for right partition
    }
}


int main()
{

    int size=0;
    cout<<"Enter Size of the array: ";
    cin>>size;
    int myarr[size];
    
    cout<<"Enter "<<size<<" integers in any order: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>myarr[i];
    }

    cout<<"Before Quick Sort: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }

    //QuickSort function
    QuickSort(myarr,0,(size-1));

    cout<<endl<<"After Quick Sort: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }

    return 0;
}
