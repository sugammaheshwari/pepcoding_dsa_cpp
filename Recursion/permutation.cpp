#include<iostream>
#include<string>
#include<vector>
using namespace std;

int permutation_01(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string nstr = str.substr(0, i) + str.substr(i + 1);
        count += permutation_01(nstr, ans + ch);
    }
    return count;
}


//this is modification of above program to find permutation of a string , it removes duplicacy in the
// string .

int permutation_02(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return(1);
    }
    
    int count=0;
    vector <bool> hashy(26,false);          // bydefault all the letters(26) are not found
    
    for(int i =0;i<str.length();i++){
        char ch=str[i];
        
        if( !hashy[ch-'a']){
            hashy[ch-'a']=true;
            string nstr=str.substr(0,i) + str.substr(i+1);
            count+=permutation_02(nstr, ans+ch);
        }
        
    }
    return(count);


}


int main(){
    
    cout<<endl<<"permutaion of string 'aab' are:"<<endl;
    int y=permutation_01("aba", "");
    cout<<"after removing redundancy :"<<endl;
    int x=permutation_02("aba", "");
}
