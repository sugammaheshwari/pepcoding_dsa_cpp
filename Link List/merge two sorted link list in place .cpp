
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

Node* sortedMerge(Node* head1,   Node* head2)
{
   
    Node *head=new Node(0),*h_copy;
    head->next=head1;
    h_copy=head;

    while(head1 && head2)
    {
        if(head1->data<=head2->data)
        {
            head=head->next;
            head1=head1->next;
        }
        else
        {
            Node *t,*t2;
            t=head->next;t2=head2->next;
            head->next=head2;
            head2->next=t;
            head2=t2;
            
            head=head->next;
        }
    }
    
    while(head2)
    {
        head->next=head2;
        head=head->next;
        head2=head2->next;
    }
   
   return h_copy->next;
}


int main()
{
    Node *l1=new Node(1);
    Node *l2=new Node(2);
    
    Node *l3=sortedMerge(l1,l2);
    
    while(l3)
    {
        cout<<l3->data<<":";
        l3=l3->next;
    }
}
