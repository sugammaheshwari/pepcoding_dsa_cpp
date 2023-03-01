
// To multiply to complex numbers and return the result as a string 


#include<iostream>
#include<map>
using namespace std;

    pair<int,int> find(string s)
    {
        auto it1=s.find('+');
        int x=stoi(s.substr(0,it1)),y=0;

        if(it1!=s.npos)
        {
            string s2=s.substr(it1+1);
            s2=s2.substr(0,s2.length()-1);
            y=stoi(s2);
        }
        return {x,y};
    }
    
    
    string complexNumberMultiply(string s1, string s2) {
        
        pair<int,int> c1,c2;
        c1=find(s1);
        c2=find(s2);
        
        int a=0,b=0;
        
        a+=-1*c1.second*c2.second;
        a+=c1.first*c2.first;
        b+=c1.first*c2.second+c1.second*c2.first;
        
        string ans;
        ans+=to_string(a)+'+'+to_string(b)+'i';
        return ans;
        
    }

