
#include<iostream>
#include<vector>

using namespace std;


int main(){
    vector<int> x={1,2,3,4,4,5,6};
    
    vector<int>::iterator itr;
    for(itr=x.begin();itr!=x.end();itr++){
        cout<<endl<<*itr;
    }
    
    vector<int> ::iterator itr1=lower_bound(x.begin(), x.end(), 4);
    // this sets the iterator to the element which has first occurance of 4 or greater than 4 ; '>='
    
    vector<int> ::iterator itr2=upper_bound(x.begin(),x.end(),5);
    // this sets the iterator to the element which is strictly greater than 5 , in our case it points to 6;  '>'
    
    cout<<"\n the lower bound using iterator is :"<<*itr1;
    cout<<"\n the uppper bound using iterator is:"<<*itr2;
    
    cout<<"\n the diffence in the positioning is :"<<itr2-itr1;

    // now say if the given list is not sorted then we can do as follows !
    
    vector<int> l={1,5,2,7,2,3,9,1,1,2};
    
    sort(l.begin(),l.end());
    // built in STL function to sort !
    
    // now to count no of occurance of 2 we can use upper and lower bound technique as follows;
    
    vector<int> ::iterator i1=lower_bound(l.begin(),l.end(),2);
    vector<int>::iterator i2=upper_bound(l.begin(),l.end(),2);
    
    cout<<"\n\n the no of times 2 has occured is :"<<i2-i1;
}

