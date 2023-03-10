/*
 
 LEET :
 Reverse Bits of an unsigned 32 bit integer
 
 example : Input: 00000010100101000001111010011100
 Output: 00111001011110000010100101000000
 
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans=0;
        
        for(int i=0;i<32;i++)
        {
            ans=(ans<<1)|(n&1);
            n=(n>>1);
        }
        
        return ans;
    }
};
