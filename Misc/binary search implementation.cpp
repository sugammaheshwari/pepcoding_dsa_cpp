
// Binary Search Implemetation
// logn complexity
// follow this way only else it causes error in edge cases !!!


#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> v={2,100,64,5,7,9};
    sort(v.begin(),v.end());
    int target=100;
    
    int l=0;
    int h=int(v.size()-1);
    
    while(l<h)
    {
        int mid=(l+h)/2;
        
        if(v[mid]<target)
            l=mid+1;
        else
            h=mid;
    }
    
    for(auto x:v)
        cout<<x<<":";
    
    cout<<"the idx is:"<<l;
    
    return 0;
}
