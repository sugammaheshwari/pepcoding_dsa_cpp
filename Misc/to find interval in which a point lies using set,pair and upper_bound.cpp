
/*
 
 problem statement: given a set of intervals , we have to find the whether a given point lies in an interval or not
 to make the problem simpler , assume that intervals don't overlapp
 
 we will use concept of sets ,maps and pairs to solve this problem and also use concept of upper bound
 
 */

#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    
    set < pair <int,int> > s;
    s.insert({401,450});
    s.insert({10,20});
    s.insert({2,3});
    s.insert({30,400});
                            // since this is a set so it is automaticlly stored in sorted order
                        // how x1<x2 and if x1==x2 then y1 < y2 comparison is done and the set is stored accordingly !
    
    int point =99;
    // this is the point we need to find the interval for
    
    pair<int,int> p={point,INT_MAX};            // we did INT_MAX to make a pair
        // why int_max only ?? because we make pair and by using upper bound ( strictly > ) we find the next pair and then we decrement
            // the iterator to point to the required interval
                // and INT_MAX makes the interval biggest so this fixes some test case like (10,0) , trying to find interval for point 10 by making
                    // a pair (10,0) as by using upper bound this would lead us to 10,20 (since x1=x2) and our algorithm would fail !
    
    
    auto itr=s.upper_bound(p);
    
    // hadnling the edge case , if upper bound returns  the first interval , like  for point = 1
    if(itr==s.begin()){
        cout<<"\n point doesnt lie in the given interval"<<endl;
    }
    else{
    itr--;          // after handling base case moving iterator to the interval where point belongs !
    
    if(itr->first<=point&& itr->second>=point)
        cout<<"\n point interval found !\t"<<itr->first<<","<<itr->second;
    
    }
}
