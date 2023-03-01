

#include<iostream>
#include<vector>
using namespace std;

void swap_(int &x,int &y)
{
    int t=y;
    y=x;
    x=t;
}
int partition (vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int pidx = start;
    
    for (int j = pidx; j <end ; j++)
        if (arr[j] < pivot)
            swap_(arr[pidx++],arr[j]);

    swap_(arr[pidx],arr[end]);
    return (pidx);
}
  
void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pidx = partition(arr, start, end);
        quickSort(arr, start,pidx-1);
        quickSort(arr,pidx+1,end);
    }
}

int main()
{
   vector<int> vec={3,8,1,5,2,9,7};
    quickSort(vec,0,6);
    for(auto x:vec)
        cout<<x<<":";
}
