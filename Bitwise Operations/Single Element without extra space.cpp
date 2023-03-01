
/*
 
 LEETCODE 137. Single Number II
 youtube explanation :  https://www.youtube.com/watch?v=ny1tk1AkON8
 
  To find the element which occurs single time in the given array where all the other elements occur exactly three times 
 
 */


int singleNumber(vector<int>& nums) {
    
    int res=0;
    
    for(int i=0;i<32;i++)
    {
        int count=0;
        for(auto x:nums)
            if( (x&(1<<i)) !=0 )                        // here the order of bracket is important if you dont put x&(1<<i) inside another bracket bitwise operation fails
                count++;                                // so be extra carefull when doing bitwise operation !!!
        res=res|((count%3)<<i);
    }
    
    return res;
}
