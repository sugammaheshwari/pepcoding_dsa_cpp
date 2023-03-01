
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

// function to reverse a link link in place
// without using extra memory
// O(n)
node *reverse_(node *head)
{
    node *h=head,*prev=NULL,*next;
    
    while(h)
    {
        next=h->next;
        h->next=prev;
        prev=h;
        h=next;
    }
    
    return prev;
}


bool is_palindrome()
{
    node *head=new node(1);
    node *h2=new node(2);
    node *h3=new node(3);
    node *h4=new node(3);
    node *h5=new node(2);
    node *h6=new node(1);
    
    head->next=h2;
    h2->next=h3;
    h3->next=h4;
    h4->next=h5;
    h5->next=h6;
    
    int n=0;
    
    node *h=head;
    while(h)
    {
        h=h->next;
        n++;
    }

    h=head;
    n=n/2;
    while(n-1>0)
    {
        n--;
        h=h->next;
    }

    node *t=h->next;
    h->next=NULL;
    node *l2=reverse_(t);

    h=head;
   
    while(h && l2)
    {
        if(h->data!=l2->data)
            return false;
        
        h=h->next;
        l2=l2->next;
    }
    
    return true;
}

int main()
{
    cout<<is_palindrome()<<endl;
}
