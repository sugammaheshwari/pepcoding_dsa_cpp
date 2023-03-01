
// Geeks : To count number of inversion in the given array 
/*
 Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
 Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
 */

//Method1 : Brute Force : time complexity O(n^2)
//Method2: Using merge sort : time compexity O(nlogn)

#include<iostream>
#include<vector>
using namespace std;

int inversions=0;

void merge_(vector<int> &arr,vector<int> &l,vector<int> &r)
{
    int i=0,j=0,m=int(l.size()),n=int(r.size());
    int k=0;
    
    while(i<m && j<n)
    {
        if(r[j]<l[i])
        {
            inversions+=(m-i);
            arr[k++]=r[j++];
        }
        else
            arr[k++]=l[i++];
    }
    
    while(i<m)
        arr[k++]=l[i++];
    while(j<n)
        arr[k++]=r[j++];
}

void merge_sort(vector<int> &arr)
{
    int n=int(arr.size());
    if(n==1)
        return;
    
    vector<int> l,r;
    for(int i=0;i<n/2;i++)
        l.push_back(arr[i]);
    for(int i=n/2;i<n;i++)
        r.push_back(arr[i]);
    
    merge_sort(l);
    merge_sort(r);
    merge_(arr,l,r);
}

int main()
{
    vector<int> v={2 ,4 ,1 ,3 ,5};
    merge_sort(v);
    cout<<inversions<<endl;
}
