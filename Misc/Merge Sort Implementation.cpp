
// Merge Sort Implementation
// Divide and Concor technique
// run time complexity - O(nlogn)
// but it uses auxilary space ( whereas quick sort sorts in place and has same run time complexity )

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &l,vector<int> &r,vector<int> &arr)
{
    int i=0,j=0,k=0;
    int l_s=int(l.size()),r_s=int(r.size()),arr_s=int(arr.size());
    
    while(i<l_s && j<r_s && k<arr_s)
    {
        if(l[i]<=r[j])
            arr[k++]=l[i++];
        else if(l[i]>r[j])
            arr[k++]=r[j++];
    }
    while(i<l_s && k<arr_s)
        arr[k++]=l[i++];
    while(j<r_s && k<arr_s)
        arr[k++]=r[j++];
}


void merge_sort(vector<int> &arr)
{
    if(arr.size()==1 || arr.size()==0)
        return;
    
    int mid=int(arr.size())/2;
    vector<int> left,right;
    
    for(int i=0;i<mid;i++)
        left.push_back(arr[i]);
    for(int j=mid;j<arr.size();j++)
        right.push_back((arr[j]));
    
    merge_sort(left);
    merge_sort(right);
    
    merge(left,right,arr);
}

int main()
{
    vector<int> vec={1,-3,22,33,29,4};
    merge_sort(vec);
    
    for(auto x:vec)
        cout<<x<<":"<<endl;
    
}
