
// Max priority Queue Implementation !!

#include<iostream>
#include<vector>
using namespace std;


class heap_{
    
    vector<int> hp;

public:
    void upheapify(int ci)
    {
        int pi=(ci-1)/2;
        if(pi>=0 && hp[pi]<hp[ci])
        {
            swap(hp[ci],hp[pi]);
            upheapify(pi);
        }
    }

    void downheapify(int ci)
    {
        int le=2*ci+1;
        int ri=2*ci+2;
        int max_=ci;
        
        if(le<hp.size() && hp[le]>hp[max_])
            max_=le;
        if(ri<hp.size() && hp[ri]>hp[max_])
            max_=ri;
        
        if(max_!=ci)
        {
            swap(hp[ci],hp[max_]);
            downheapify(max_);
        }
    }
    
    int top(){
        return hp[0];
    }
    
    void pop()
    {
        int n=int(hp.size());
        swap(hp[0],hp[n-1]);
        hp.erase(hp.begin()+n);
        downheapify(0);
    }
    
    void push(int x)
    {
        hp.push_back(x);
        int n=int(hp.size());
        upheapify(n-1);
    }
    
    void display()
    {
        cout<<"\n The max_heap or max priority queue is: ";
        for(auto x:hp)
        {
            cout<<x<<":";
        }
        cout<<endl;
    }
    
    void set_hp(vector<int> &arr)
    {
        for(auto x:arr)
            push(x);
        
    }
    
    
};


int main()
{
    heap_ h1;
    vector<int> nums={10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    h1.set_hp(nums);
    h1.display();
}
