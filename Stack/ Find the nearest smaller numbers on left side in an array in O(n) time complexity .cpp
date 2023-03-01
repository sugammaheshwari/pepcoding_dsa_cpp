
/*
 
 Find the nearest smaller numbers on left side in an array in O(n) time complexity
 / using stack is the optimal solution !!! /

 Given an array of integers, find the nearest smaller number for every element such that the smaller element is on left side.
 
 Input:  arr[] = {1, 6, 4, 10, 2, 5}
 Output:         {_, 1, 1,  4, 1, 2}
 First element ('1') has no element on left side. For 6,
 there is only one smaller element on left side '1'.
 For 10, there are three smaller elements on left side (1,
 6 and 4), nearest among the three elements is 4.

 Input: arr[] = {1, 3, 0, 2, 5}
 Output:        {_, 1, _, 0, 2}
 
 
 */

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n=6;
    int arr[6]={1,6,4,10,2,5};
    stack<int> st;
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=arr[i])
            st.pop();
        if(st.empty())
            cout<<"-,";
        else
            cout<<st.top()<<",";
        st.push(arr[i]);
    }
}
