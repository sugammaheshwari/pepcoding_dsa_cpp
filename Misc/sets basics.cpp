

#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int> s;
    s.insert(1);                // insertion operation take log(n) time !
    s.insert(-10);                  // this makes sets very powerfull !
    s.insert(223);
    s.insert(-5);
    
    for(int x:s)
        cout<<endl<<x;

    //using find to find element in a set !
    set<int>::iterator it=s.find(-10);
    cout<<*it;
    
    // using auto keyword to
    
    auto it2=s.find(-11);
    if(it2==s.end())
        cout<<"\n not found ";
    
    // lower bound and upper bound works differently in set as set is already sorted 1
    // here is the syntax for the same !
    
    auto i=s.lower_bound(-10);
        // where as in vector syntax was like upper_bound(v.begin(),v.end(),10)         // obviously after sorting lower bound was called !
    
    cout<<endl<<*i;
    
    s.erase(-5);            // removes element in 0(1) time;
}
