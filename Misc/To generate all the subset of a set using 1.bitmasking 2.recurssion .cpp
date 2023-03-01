
// to generate all the subset of a set

// Method 1 : By using BitMasking
// Method 2 : by using recurrsion

#include<iostream>
#include<vector>
using namespace std;

void bit_masker_method()
{
    vector<char> v={'A','B','C','D'};
    int N=int(v.size());
    
    int tot=1<<N;

    for(int n=0;n<tot;n++)
    {
        for(int b=0;b<N;b++)
            if((n&(1<<b)))
                cout<<v[b]<<" ";
        cout<<endl;
    }
}

void rec_method(int b,vector<char> &v,string s)
{
    if(b==v.size())
    {
        cout<<s<<endl;
        return;
    }
    
    rec_method(b+1, v,s+v[b]);
    rec_method(b+1, v,s);
}

int main()
{
    vector<char> v={'A','B','C','D'};
    rec_method(0,v,"");
}
