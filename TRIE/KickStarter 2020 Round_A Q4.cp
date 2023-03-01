
// Google KickStarter 2020 Problem D
// Link : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3


#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int word_end;
    int h;
    vector<node *> children;
    
    node()
    {
        word_end=0;
        h=0;
        children.resize(26,NULL);
    }
};

node *ROOT;
int ans;

void insert(string s)
{
    node *r=ROOT;
    for(int i=0;i<s.length();i++)
    {
        int idx=s[i]-'A';
        if(!r->children[idx])
            r->children[idx]=new node();
        r->children[idx]->h=i+1;
        r=r->children[idx];
    }
    r->word_end++;
}

int dfs(node *r,int k)
{
    if(!r)
        return 0;
    
    int a=r->word_end;
    for(auto child:r->children)
        a+=dfs(child,k);
    
    ans+=(a/k)*r->h;
    return a%k;
}



int main()
{
    int T;
    cin>>T;
    
    for(int t=1;t<=T;t++)
    {
        ROOT=new node();
        int n,k;
        cin>>n>>k;
        
        while(n--)
        {
            string s;
            cin>>s;
            insert(s);
        }
        ans=0;
        ans+=dfs(ROOT,k)/k;

    cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}

