
// to generate all posible subset sum in O(n^2) time !


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums={1,2,3,4,5,6};
    int n=int(nums.size());
    vector<int> sum(n);
    sum[0]=nums[0];
    
    for(int i=1;i<n;i++)
        sum[i]=sum[i-1]+nums[i];
    
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            cout<<(sum[j]-sum[i]+nums[i])<<endl;
    
    
}
