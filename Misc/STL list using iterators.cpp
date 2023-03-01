
// learning how to use STL list
//list <int> is a STL doubly linked list which can be used through iterator
// the use is depicted below

#include<iostream>
#include<list>
using namespace std;

int main(){
    
    //showing how to print list using iterator
    
    list <int> l;
    
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    
    list <int> :: iterator it;
    it=l.begin();
    
    for(;it!=l.end();it++){
        cout<<endl<<*it;
    }
    
    
    //showing how to print list using reverse iterator;
    
    list <char> l2;
    l2.push_front('a');
    l2.push_front('b');
    l2.push_front('c');
    l2.push_front('d');

    list <char> :: reverse_iterator rit;
    rit=l2.rbegin();
    
    for(;rit!=l2.rend();rit++){
        cout<<endl<<*rit;
    }
    
}
