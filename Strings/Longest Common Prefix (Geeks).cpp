
// GEEKS : longest common prefix for n_given strings
// link: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0

#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        vector<string> s;
        
        for(int j=0;j<n;j++)
            {
                string x;
                cin>>x;
                s.push_back(x);
            }
        
        vector<int> index(n,0);
        string ans="";
    
        while(index[0]<s[0].length())
        {
            bool res=true;
            for(int i=1;i<n;i++)
            {
                if(res && s[i].length()==index[i])
                    res=false;
                if(res && s[i][index[i]++]!=s[0][index[0]])
                    res=false;
            }
            if(res)
                ans+=s[0][index[0]++];
            else
                break;
            
        }
        
        if(ans=="")
            cout<<-1;
        else
            cout<<ans;
    }
        return 0;
}
