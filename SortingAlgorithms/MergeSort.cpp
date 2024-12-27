#include<iostream>
using namespace std;

//merge sort sorting algorithm

//merge function
void merge(int arr[], int l, int m, int r)
{
    int i=l; //startting index for left subarray
    int j=m+1; //starting index for right subarray
    int k=l; //starting index for temporary

    int size = (r-l)+1;
    int temp[size]; //temporary

    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i]; //arr[i] is smaller than arr[j]
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j]; //arr[i] is smaller than arr[i]
            j++;
            k++;
        }
    }
    while(i<=m)
    {
            temp[k]=arr[i]; //copying all elements from left subarray to temp as it is
            i++;
            k++;
    }
    while(j<=r)
    {
            temp[k]=arr[j]; //copying all elements from right subarray to temp as it is
            j++;
            k++;
    }
    for(int s=l;s<=r;s++)
    {
        arr[s]=temp[s];
    }

}

//merge sort function
void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}



int main()
{   
    int size;

    cout<<"Enter Size of the array: ";
    cin>>size;

    // int arr[5] = {4,6,1,2,7};
    cout<<"Enter "<<size<<" no of elements of the array: "<<endl;
    int myarr[size];
    for(int i=0;i<size;i++)
    {
        cin>>myarr[i];
    }

    cout<<"Before Merge Sort: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }

    //mergesort function
    mergeSort(myarr,0,(size-1));

    cout<<endl<<"After Merge Sort: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<myarr[i]<<" ";
    }


    return 0;
}
