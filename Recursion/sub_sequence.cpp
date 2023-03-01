#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

string seq;

int subseq(string s,string ans){
    if(s.length()==0){
        seq+=" "+ans;         // printing the substring sequence
        return 1;
    }
    
    string s_=s.substr(1);
    char c=s[0];
    subseq(s_,ans+c);
    subseq(s_,ans);
    
    return 1;
    
}

void display(vector<string> &arr, int vidx)
{
    if (vidx == arr.size())
        return;
    cout << arr[vidx] << " ";

    display(arr, vidx + 1);


}

// this code is missing the printing of 'abc' debug later

vector<string> sub_seq(string s){
    if(s.length()==0){
        vector<string> base;
        base.push_back("");
        return(base);
    }
    
    string nstr = s.substr(1);
    char ch=s[0];

    vector<string> recAns = sub_seq(nstr);
    int size = int (recAns.size());
    for (int i = 0; i < size; i++) {
        recAns.push_back(ch + recAns[i]);
    }

        return recAns;
}



int main(){
    
    vector<string> s_;
    s_=sub_seq("abc");
    display(s_, 0);
    
}
