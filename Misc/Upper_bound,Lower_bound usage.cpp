
/*
 
TO demonstrate the use of UpperBound , LowerBound and binary search
 inbuilt O(logn) algorithms in STL's algorithm> header file !!
 
 */


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    
    // lower bound !!
    vector<int> v={1,3,7,9,15};
    auto it1=lower_bound(v.begin(),v.end(),8);
    auto it2=lower_bound(v.begin(),v.end(),7);
    cout<<*it1<<":"<<*it2<<endl;
    
    // upper bound !!!
    // [) ye wali limit
    auto it3=upper_bound(v.begin(),v.end(),8);
    auto it4=upper_bound(v.begin(),v.end(),7);
    
    cout<<*it3<<":"<<*it4<<endl;
    
    
    // binary search
    
    auto it=binary_search(v.begin(), v.end(), 15);
        if(it)
            cout<<"found";
}
