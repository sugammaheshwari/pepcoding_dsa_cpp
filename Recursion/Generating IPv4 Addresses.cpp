
// To generate A valid IPv4 Address
// Used cut strategy !!

// Geeks Question : https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

// please note here instead of using STIO i used STOL (String to long ) to fix the overflow error !!!!

#include<iostream>
#include<vector>
using namespace std;

vector<string> ans;

void make(string &s,int sidx,int cuts,string a)
{
    if(cuts==0)
    {
        string k=s.substr(sidx);
        if( (k[0]=='0' && k.length()==1) || (k[0]!='0' && stol(k)<256) )
        {
            a+=s.substr(sidx);
            ans.push_back(a);
        }
        return;
    }
    
    for(int i=sidx;i<s.length()-1;i++)
        if( s.length()-(i+1)>cuts-1 && stol(s.substr(sidx,i-sidx+1))<256)
        {
            if(i==sidx && s[i]=='0')
            {
                make(s,i+1,cuts-1,a+"0.");
                break;
            }
            else
                make(s,i+1,cuts-1,a+s.substr(sidx,i-sidx+1)+".");
        }
}

int main()
{
    ans.clear();
    //string s="63206";
    //    string s="50361";                     // mentioning all the difficult test case
    //string s="43030";
    //string s="234234234234234";
    string s="67535629";
    make(s,0,3,"");
    
    for(auto x:ans)
        cout<<x<<endl;
    cout<<endl;
    
}



