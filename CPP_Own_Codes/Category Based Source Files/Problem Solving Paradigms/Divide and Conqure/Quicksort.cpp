#include <bits/stdc++.h>
using namespace std;

int Partition(int a[], int start, int End)
{
    int pivot = a[End];
    int pivot_index = start;

    for(int i = start; i <= End-1; i++)
    {
        if(a[i] < pivot)
        {
            int temp = a[pivot_index];
            a[pivot_index] = a[i];
            a[i] = temp;
            pivot_index++;
        }
    }
    int temp = a[pivot_index];
    a[pivot_index] = a[End];
    a[End] = temp;
    return pivot_index;
}
void Quicksort(int a[], int start, int End)
{
    if(start < End)
    {
        int pivot_index = Partition(a, start,End);
        Quicksort(a, start, pivot_index-1);
        Quicksort(a, pivot_index+1, End);
    }
}

int main()
{
    int arr[6] = {5,3,1,0,4,2};
    Quicksort(arr, 0, 5);
    for(int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
