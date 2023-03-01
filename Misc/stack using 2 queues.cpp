#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue <int> q1,q2;
    int arr[7]={100, 80, 60, 70, 60, 75, 85};
    
    q1.push(arr[0]);
    for(int i=1;i<7;i++){
        
        
        while(q1.empty()==false){
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(arr[i]);
        
        while(q2.empty()==false){
            
            q1.push(q2.front());
            q2.pop();
        }
        
        
    }
    
    for(int i=0;i<7;i++){
        cout<<endl<<q1.front();
        q1.pop();
    }
}
