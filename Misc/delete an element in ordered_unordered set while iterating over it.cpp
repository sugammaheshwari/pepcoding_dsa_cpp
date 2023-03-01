
// Method to  delete an element in ordered/unordered set while iterating over it !!!
// thing to take care of is that when we use erase function , it automatically points to the next position available
// thus there is no need to increment the iterator !!!!

#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;
    for(int i=1;i<=20;i++)
        s.insert(i);
    
    for(auto it=s.begin();it!=s.end();)
        if((*it%2)==0)
            it=s.erase(it);
        else
            it++;
    
    for(auto it=s.begin();it!=s.end();it++)
        cout<<*it<<":";
    
   
}
