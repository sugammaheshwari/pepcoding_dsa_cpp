

#include<iostream>
#include<vector>


using namespace std;


int coin_infi_combo(vector<int> &coins,int idx,int tar,string ans){
    
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    
    int count=0;
    for(int i=idx;i<coins.size();i++){
        
        if(tar-coins[i]>=0){
            count+=coin_infi_combo(coins, i+1, tar-coins[i], ans +" " + to_string(coins[i]));
        }
    }
    
    return(count);
}



int main(){
 
    vector<int> coins {1,6};
    int x=coin_infi_combo(coins, 0, 7, "");
    cout<<x;
}
