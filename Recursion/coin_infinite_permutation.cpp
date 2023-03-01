

#include<iostream>
#include<vector>


using namespace std;

int coin_infinite_permutation(vector<int> &coin,vector<bool> vis,int tar,string ans){
    
    if(tar==0){
        cout<<ans<<endl;
        return(1);
    }
    
    int count=0;
    for(int i=0;i<coin.size();i++){
        if(tar>=coin[i] && !vis[i]){
            vis[i]=true;
            count+=coin_infinite_permutation(coin, vis, tar-coin[i], ans +" " + to_string(coin[i]));
            vis[i]=false;
        }
        
        
    }
    return(count);
    
}



int main(){
 
    vector<int> coins {0,1,2};
    vector<bool> mark (3,false);
    int x=coin_infinite_permutation(coins,mark, 3, "");
    cout<<x;
}
