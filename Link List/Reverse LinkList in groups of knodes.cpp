
// Reverse a Linked List in groups of given size.
// LEETCODE HARD PROBLEM !!!


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

Node *rev_list(Node *head)
{
    Node *prev=NULL,*next;
    
    while(head)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}


Node *rev_list_in_groups(Node *head,int len,int k)
{
    if(len<k || head==NULL)
        return head;
    
    Node *h=head;
    int c=k-1;
    while(c>0)
    {
        c--;
        h=h->next;
    }
    
    Node *t=h->next;
    h->next=NULL;
    Node *new_head=rev_list(head);
    head->next=rev_list_in_groups(t,len-k,k);
    
    return new_head;
}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(8);
    head->next->next->next->next->next=new Node(11);


    
    
    head=rev_list_in_groups(head,6,3);
    
    while(head)
    {
        cout<<head->data<<":";
        head=head->next;
    }
}
