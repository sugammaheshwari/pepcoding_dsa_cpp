
#include<iostream>
#include<stack>
using namespace std;

// programe to find the next greatest (right) element of an array

int main(){
    stack<int> s;
    int arr[]={5,7,2,9,11};
    
    for(int i=0;i<5;i++){
            
        if(s.empty()){
            s.push(arr[i]);
        }
        while(s.empty()==false && s.top()<arr[i]){
            cout<<s.top()<<"-->"<<arr[i]<<endl;
            s.pop();
        }
        if(i!=0)
        s.push(arr[i]);
    }
   
}
