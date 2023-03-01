
// using map in c++ to count no of occurences of a character !

#include<iostream>
#include<map>

using namespace std;

int main(){
    
    map<char,int> count;
    
    string s="aaabccvbgsfghytresdghjkiuesjkiu654ewasghju";
    
    for(char c:s){
        count[c]++;
    }
    
    for(auto x:count){
        cout<<x.first<<":"<<x.second<<endl;
    }
    
    // dipplaying using iterator !
    cout<<"\n displyaing using second method !";
    
    map<char,int> ::iterator itr=count.begin();
      
      for(;itr!=count.end();itr++){
          cout<<itr->first<<":"<<(itr->second)<<endl;
      }
    
}
