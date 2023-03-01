
/*

Bit manuplation 
Pepcoding Tutorial !

1.to get the rightmost set bit mask of a given number. 
2. to count no of on bit in 0(b) time complexity where b is the no of on bits.

Notes:

2's compliment of binary number = 1's compliment + 1 = -ve of that number 
The above tasks can be done in 0(no of bits) but we are implementing efficient algorithms!

*/

// returns the set right most bit mask of a given number
// for example if the number is 1011101111000 ->  0000000001000

#include<iostream>
using namespace std;

int r_m_s_b_mask(int x)
{
	return x&-x;
}

int count_on_bits(int x)
{
	int count=0;

	while(x!=0)
	{
		int mask=r_m_s_b_mask(x);
		x=x-mask;
		count++;
	}

	return count;
}

int main()
{
    cout<<count_on_bits(5496);
}