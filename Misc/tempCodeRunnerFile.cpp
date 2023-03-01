#include<iostream>
#include<vector>
using namespace std;

bool ne=false;
string s="abcedf";
int s_l=s.length();
int l=4;
vector<int> bit_state(s_l,0);

bool hasNext()
{
    return ne;
}

void fix_bit_state()
{
    int on_count=0;bool returner=false;
    for(int i=s_l-1;i>=0;i--)
    {
        if(bit_state[i])
            on_count++;
        if(i==s_l-1 || !bit_state[i])
            continue;
        if(!bit_state[i+1])
        {
            bit_state[i]=0;int j=i+1;
            while(j<i+1+on_count) bit_state[j++]=1;
            while(j<s_l) bit_state[j++]=0;
            returner=true;
            break;
        }
    }

    if(!returner)
        ne=false;
}

string next()
{
    string ans="";
    for(int i=0;i<s_l;i++)
        if(bit_state[i])
            ans+=s[i];
    
    fix_bit_state();
    return ans;
}



int main()
{
    // constructor call
    ne=true;
    for(int i=0;i<l;i++)
        bit_state[i]=1;

    cout<<endl<<next();

}