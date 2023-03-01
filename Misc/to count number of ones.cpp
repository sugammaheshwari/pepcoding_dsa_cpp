
// to find the number of 1's in a given number (binary number )


#include<iostream>
using namespace std;

// best soltution ( fastest )

int count_1s_best(int a){
    
    int count=0;
    while(a!=0){
        count++;
        a&=a-1;
    }
    return(count);
}


// method 2 is by creating a mask (using bitwise operations)

int count_1s(int a){
    
    
    int count = 0;
    for (int i = 0; i < 32; i++) {              // because integer can have maximumm of 32 bits.
        int mask = (1 << i);                    // shifts 1 to i right places , binary right shift
        if ((a & mask) != 0)                    // for example  1 << 2      gives 100.
            count++;
    }

    return count;

}


int main(){
    
    cout<<"the number is 1's is :"<<count_1s_best(3);
    
}
