
// LEET : 84. Largest Rectangle in Histogram
// Video link explanation : https://www.youtube.com/watch?v=qj4RcJbp03g&t=663s

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int largestRectangleArea(vector<int>& h)
{
if(h.size()==0)
    return 0;
if(h.size()==1)
    return h[0];

int n=int(h.size());
int ans=0;

stack<int> st;
st.push(0);

for(int i=1;i<n;i++)
{
    int curr=h[i];
    if(curr>=h[st.top()])
        st.push(i);
    else
    {
        while(!st.empty() && curr<h[st.top()])
        {
            int temp=h[st.top()];st.pop();
            if(st.empty())
                ans=max(ans,temp*i);
            else
                ans=max(ans,temp*(i-st.top()-1));
        }
        st.push(i);
    }
}

while(!st.empty())
{
    int temp=h[st.top()];st.pop();
    if(st.empty())
        ans=max(ans,temp*n);
    else
        ans=max(ans,temp*(n-st.top()-1));
}


return ans;
}
