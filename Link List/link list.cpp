#include<iostream.h>
using namespace std;

struct node{
    int data;
    node *next;

};

node *start=new node();

start->data=10;
*t1=new node();

start->next=t1;

t1->data=20;
t1->next=NULL;

// travesing a link list ;

*t=new node();
while (t->next!=NULL){
    print(t->data);
    t=t->next;
}

