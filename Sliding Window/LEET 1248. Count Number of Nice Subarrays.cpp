
//1248. Count Number of Nice Subarrays
// naive solution timed out
// used sliding window technique to solve it in O(n)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> v;
        v.push_back(-1);
        
        for(int i=0;i<n;i++)
            if(nums[i]&1)
                v.push_back(i);
        
        int i=1,j=i+k-1;
        int v_=v.size(),count=0;
        while(j<v_)
        {
            if(j+1<v_)
                count+=(v[i]-v[i-1])*(v[j+1]-v[j]);
            else
                count+=(v[i]-v[i-1])*(n-v[j]);
            i++;j++;
        }
        
        return count;
    }
};

