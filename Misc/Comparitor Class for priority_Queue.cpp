
#include<iostream>
#include<queue>
using namespace std;

// please not priority_queue main ulta hota hai
// when we used to write comparitor for sort function x<y meant sort in increasing order
// but here it means in decreasing order !!!

struct comp
{
    bool operator()(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]<v2[1];
    }
};


int main()
{
    
    priority_queue<vector<int>,vector<vector<int>>,comp> pq;
    
    pq.push({2,4});
    pq.push({2,8});
    
    cout<<pq.top()[0]<<":"<<pq.top()[1];
    
}
