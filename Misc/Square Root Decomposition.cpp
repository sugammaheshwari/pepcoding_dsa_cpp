
/*
                                                SQUARE ROOT DECOMPOSTION !!!
 
 Sqrt (or Square Root) Decomposition Technique is one of the most common query optimization technique used by competitive programmers. This technique helps us to reduce Time Complexity by a factor of sqrt(n).
 */

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int n,bs;
void update(vector<int> &v,vector<int> &b,int idx,int val)
{
    b[idx/bs]-=(v[idx]-val);
    v[idx]=val;
}

int fetch(vector<int> &v,vector<int> &b,int l,int r)
{
    int sum=0;
    
    while(l<=r && l%bs!=0)
        sum+=v[l++];            // adding the elements which occur before the first bucket elements
    
    while((l+bs)<=r){
        sum+=b[l/bs];
        l+=bs;
    }
    
    while(l<=r)             // adding the remaining elements of the last bucket , notice here we dont need the l%bs!=0 condition!
        sum+=v[l++];
    
    return sum;
}


int main()
{
    cin>>n;bs=sqrt(n);
    vector<int> v(n),b(bs+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        b[i/bs]+=v[i];
    }
    int Q;cin>>Q;                       // no of queries
                                        // 0-update query ,1-fetch query !
    while(Q--)
    {
        int q;cin>>q;
        if(q==0){
            int idx,val;
            cin>>idx>>val;
            update(v,b,idx,val);
        }
        else{
            int l,r;                // fetch sum bw l and r indices both inclusive !
            cin>>l>>r;
            cout<<fetch(v,b,l,r);
        }
    }
}
