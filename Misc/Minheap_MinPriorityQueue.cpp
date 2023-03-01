
// defining minheap (min-priority queue for various container types !!!

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   
}
