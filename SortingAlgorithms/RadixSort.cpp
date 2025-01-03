#include<iostream>
using namespace std;

int GetMax(int arr[], int size)
{
    int max = arr[0];
    for(int i=1; i<size; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}


void CountingSort(int arr[],int size, int div)
{
    int output[size];
    int count[10] = {0};

    for(int i=0;i<size;i++)
    {
        count[ (arr[i]/div)%10]++;
    }

    for(int i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }

    for(int i=size-1;i >= 0;i--)
    {
        output[count[(arr[i]/div)%10] - 1] = arr[i];
        count[(arr[i]/div)%10]--;
    }


    for(int i=0;i<size;i++)
    {
        arr[i] = output[i];
    }

}

void RedixSort(int arr[],int size)
{
    int m = GetMax(arr,size);
    for(int div=1;m/div>0;div*=10)
    {
        CountingSort(arr, size, div);
    }
}

int main()
{
    int size;
    cout<<"Enter Size of the array: ";
    cin>>size;
    int arr[size];

    cout<<"Enter "<<size<<" integers in any order"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    cout<<"Before Sorting: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    RedixSort(arr,size); // RADIX SORT CALLED HERE

    cout<<endl<<"After Sorting: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
