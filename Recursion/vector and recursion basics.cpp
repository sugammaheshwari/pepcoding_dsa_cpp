

// vector use and recursion
#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &arr, int vidx)
{
    if (vidx == arr.size())
        return;
    display(arr, vidx + 1);

    cout << arr[vidx] << " ";

}

bool find_data(vector <int> &arr, int vidx, int data){
    if(vidx==arr.size()) return (0);
    if(arr[vidx]==data) return (1);
    return(find_data(arr, vidx+1, data));
}

// this is recursive approach to find data searching from the last element is found then returns true else searches for the previous elements till the first element , see the code below ...

bool find_data_02(vector<int> &arr, int vidx,int data){
    if(vidx==arr.size()) return false;
    
    bool recAns=find_data_02(arr, vidx+1, data);
    if(recAns) return true ;
    return(arr[vidx]==data);
    
}

// function to return first index where an element is found in a vector

int first_index(vector<int> &v1,int vidx,int data){
    
    if(vidx==v1.size()) return -1;
    if(v1[vidx]==data) return vidx;
    return(first_index(v1, vidx+1, data));
}

// function to return the last index where an element is found in a vector

int last_index(vector<int> &v1,int vidx, int data){
    if(vidx==v1.size()) return -1;
    
    int rec_ans=last_index(v1, vidx+1, data);
    if(rec_ans!=-1) return rec_ans;
    
    return (v1[vidx]==data?vidx:-1);
}


int main(){
    vector <int> v1;
    for(int i=0;i<=10;i++){
            
    v1.push_back(i);
    }
    v1.push_back(3);
    
    display(v1,0);
    cout<<endl<<find_data(v1, 0, 9);
    cout<<endl<<find_data_02(v1, 0, 15);
    
    cout<<endl<<"first index occurance of element '3' is :"<<first_index(v1, 0, 3)<<endl;
    cout<<endl<<"last index occurance of element '3' is :"<<last_index(v1, 0, 3)<<endl;

}


/* how to print vector elements
    for(auto i=v1.begin();i!=v1.end();i++){
       cout<<endl<<*i;
    */
