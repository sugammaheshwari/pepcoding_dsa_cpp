
// To implement heap(Max-Heap) using vector

#include<iostream>
#include<vector>
using namespace std;


class max_heap{
private:
    vector<int> heap;
public:
      
    void swap_(int v1,int v2)
    {
        int t=heap[v1];
        heap[v1]=heap[v2];
        heap[v2]=t;
    }
    
    void insert(int x)
    {
        heap.push_back(x);
        int size=(int)heap.size();
     
        if(size==1)
            return ;
        else if(size==2)
        {
            if(x>heap[0])
                swap_(0,1);
        }
        else
        {
            int v2=size-1;
            int v1=(int)(v2-1)/2;
            while(v1>=0 && heap[v1]<heap[v2])
            {
                swap_(v1,v2);
                v2=v1;
                v1=(int)(v2-1)/2;
            }
        }
    }
    
    void heapify(int size)
    {

        if(size<=2)
            return;
        int v1=0;
        int v2;
        
        if(heap[1]>heap[2])
            v2=1;
        else
            v2=2;
        
        while(heap[v1]<heap[v2])
        {
            swap_(v1,v2);
            v1=v2;
            if(2*v1+2<size && heap[2*v1+1]>heap[2*v1+2])
            {
                v2=2*v1+1;
            }
            else if(2*v1+2<size && heap[2*v1+1]<heap[2*v1+2])
            {
                v2=2*v1+2;
            }
            
        }
    }
    
    int del_()
    {
        int size=(int)heap.size();

        if(size==0)
            return 0;
        else if(size==1)
        {
            heap.resize(0);
            return 1;
        }
        else if(size==2)
        {
            heap[0]=heap[1];
            heap.pop_back();
            return 1;
        }
        else
        {
            heap[0]=heap[size-1];
            heap.pop_back();
            size--;
            
            heapify(size);
            return 1;
        }
        
        return 0;
        
    }
    
    
    void heap_sort()
    {
        if(heap.size()<=1)
            return;
        if(heap.size()==2 && heap[1]<heap[0])
            swap_(1,0);
        
        int sor_TED_idx=(int)heap.size()-1;
        
        while(sor_TED_idx>=3)
        {
            swap_(0,sor_TED_idx);
            heapify(sor_TED_idx);
            sor_TED_idx--;
        }
        
        if(sor_TED_idx==2)          // since i have written heapify for heap with 3 elements thus there is a need to handle this explicitly !
        {
            swap_(0,2);
            int mi=min(heap[1],heap[0]);
            int ma=max(heap[1],heap[0]);
            heap[1]=ma;heap[0]=mi;
        }
        
        
    }
    
    void show_heap()
    {
        cout<<endl;
        for(int i=0;i<heap.size();i++)
            cout<<heap[i]<<":";
    }
    
};



int main(){
    max_heap h1;
    
    
    h1.insert(50);
    h1.insert(40);
    h1.insert(30);
    h1.insert(18);
    h1.insert(-11);

    h1.insert(20);
    h1.insert(400);
    h1.insert(7);
    h1.insert(-1);

    h1.insert(222);
    h1.insert(118);
    h1.insert(-121);

    cout<<endl<<"after  insertions:";




    h1.show_heap();
    cout<<endl<<"after  deletions:";

    h1.del_();
    h1.del_();
    h1.del_();
    h1.del_();
    h1.show_heap();

    cout<<"\n Heap after heap-sort using heapify fucntion is :"<<endl;
    h1.heap_sort();
    
    h1.show_heap();



}
