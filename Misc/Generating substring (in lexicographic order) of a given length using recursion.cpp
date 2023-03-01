
#include<iostream>
#include<vector>
using namespace std;


void subset(string s,int idx,int l,string ans)
{
    if(l==0)
    {
        cout<<ans<<endl;
        return;
    }

    if(idx>=s.length() || l<0) return;

    subset(s,idx+1,l-1,ans+s[idx]);
    subset(s,idx+1,l,ans);
}


int main()
{
    string s="abcdef";
    int l=3;

    subset(s,0,l,"");
}