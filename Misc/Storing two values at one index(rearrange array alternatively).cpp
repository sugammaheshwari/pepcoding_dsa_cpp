
// Technique to store two values at one location using some math
// Ques: Rearrange array alternatively
// video link for explanation : https://www.youtube.com/watch?v=ZRoVWxBngX0

#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> v={1,7,4,9,2};
    int n=int(v.size());
    sort(v.begin(),v.end());
    int max_idx=n-1,min_idx=0,max_ele=v[n-1]+1;

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            v[i]=v[i]+ (v[max_idx--]%max_ele)*max_ele;
        else
            v[i]=v[i]+ (v[min_idx++]%max_ele)*max_ele;
    }
    
    // To display the original array
    cout<<"the sorted orignal array is"<<endl;
    for(auto x:v)
        cout<<x%max_ele<<" ";
    cout<<endl;
    
    // to display alternating array
    cout<<"the alternating array is"<<endl;
    for(auto x:v)
        cout<<x/max_ele<<" ";
    
}
