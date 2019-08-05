#include <bits/stdc++.h>
using namespace std;
#define INFINITY 999999

void Merge(int a[], int low, int mid, int high)
{
    int n1 = mid-(low-1);
    int n2 = high - mid;
    int left[n1+1];
    int right[n2+1];

    for(int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    }
    for(int j = 0; j < n2; j++)
    {
        right[j] = a[mid + j + 1];
    }
    left[n1] = INFINITY;
    right[n2] = INFINITY;

    for(int k = low, i = 0, j = 0; k <= high; k++)
    {
        if(left[i] < right[j])
        {
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
    }
}

void Merge_sort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        Merge_sort(a, low, mid);
        Merge_sort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int arr[6] = {5,3,1,0,4,2};
    Merge_sort(arr, 0, 5);
    for(int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

