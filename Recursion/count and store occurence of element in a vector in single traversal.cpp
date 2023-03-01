
#include<iostream>
#include<vector>
using namespace std;

/* given a dynamic array (vector) how can you count and store the occurence of an elemnt in the array
 in single traversal , ie you are only allowed to visit each element once
 
 The above problem can be solved using recursion and we exploit the property of going in and coming out out recursion to first count the occurence of element in the vecor and then when comming out we add the element's position to our dynamically ( size = count ) created array as illustrated beautifully by the code below.
 
 */

vector<int> store_all_indices(vector<int> &arr, int vidx,int data , int count=0){
    // base case is we have counted the no of time element has occured and thus making and returning a vector of size count
    
    if(vidx==arr.size()){
        vector<int>  base(count);
        return(base);
    }
    
    if(arr[vidx]==data)
        count++;
    
    vector<int> rec_ans=store_all_indices(arr, vidx+1, data, count);
    
    if(arr[vidx]==data)
        rec_ans[count-1]=vidx;
    
    return(rec_ans);
    
}

// clearly fibonaki series can be printed using recursion and here we dont even need to use a temp variable
void fibo_naki(int a ,int b, int n){
    if (n==0) return;
    cout<<endl<<a<<"\t";
    fibo_naki(b, a+b, n-1);
}

// this function below uses recursion to calculate a^b and reduces number of calls to logb (with base 2)
// and is used to computer results faster

int power_btr_function(int a ,int b){
    if(a==0) return(0);
    if(b==1) return(1);
    
    int t_ans=power_btr_function(a, b/2);
    t_ans*=t_ans;
    
    if(b%2==0) return t_ans;
    else
        return t_ans*a;
    
}

void display(vector<int> &arr, int vidx)
{
    if (vidx == arr.size())
        return;
    cout << arr[vidx] << " ";

    display(arr, vidx + 1);


}


int main(){
   // fibo_naki(0, 1, 10);
    vector<int> aa;
    aa.push_back(5);
    aa.push_back(3);
    aa.push_back(6);
    aa.push_back(7);
    aa.push_back(3);
    aa.push_back(6);
    aa.push_back(121);
    
    vector<int> x=store_all_indices(aa,0,3,0);
    
    display(x,0);
}
