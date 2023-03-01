
// Q: TO generate all the possible subsequences using recursion for a given string !!!
// here i had to use map because some strings are regenerated (occur more than once ) so map just stores the unique keys
// always draw tree diagram to undersrtand the behavious of recursion


#include<iostream>
#include<map>
using namespace std;

map<string,int> unique_string;

void _subsequences(string s,int idx,string ans)
{
    if(idx==s.length()){
        unique_string[ans]++;
        return;
    }
    
    for(int i=idx;i<s.length();i++){
        unique_string[ans]++;
        _subsequences(s,i+1,ans+s[i]);

    }
}

int main()
{
    string s="abcd";
    _subsequences(s,0,"");
    
    for(auto itr:unique_string)
        cout<<itr.first<<endl;
    
}
