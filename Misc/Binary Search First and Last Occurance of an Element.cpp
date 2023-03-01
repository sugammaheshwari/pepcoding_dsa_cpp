
#include<iostream>
#include<vector>
using namespace std;

int b_Search_last_occurance(vector<int> &v,int t)
{
    int s=0;
    int e=int(v.size())-1;
    
    while(s<e)
    {
        int mid=(s+e)/2;
        
        if(s+1==e)                  // this break statment is imp to exit the infinte loop
            break;                // test cases like: [8,8,8,8,8] fail !!! is this is not present !
                                
        if(v[mid]==t)
            s=mid;
        else if(v[mid]>t)
            e=mid-1;
        else
            s=mid+1;
    }
    if(v[e]==t)
        return e;
    if(v[s]==t)
        return s;
    return -1;
}


int b_search_first_occurance(vector<int> &v,int t)
{
    int s=0;
    int e=int(v.size())-1;
    
    while(s<e)
    {
        int mid=s+(e-s)/2;
        if(v[mid]==t)
            e=mid;
        else if(v[mid]>t)
            e=mid-1;
        else
            s=mid+1;
    }
    return v[s]==t?s:-1;
 }

int main()
{
    vector<int> v={5,7,8,8,8,8,8,9,10};
    int x=8;
    cout<<b_Search_last_occurance(v,x)<<","<<b_search_first_occurance(v,x);
}
