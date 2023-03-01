
// reversal of link list using 3 method
// 1. regular by making new list
// 2. by using auxilary data structure like stack
// 3. new method my using recursion

#include<iostream>
#include<stack>

using namespace std;

struct node
{
    int data;
    node *next;
};

node* inputlist(struct node *head)
{
    struct node *temp;

    cout<<"\n enter 5 values:";
    for(int i=0;i<5;i++)
    {
        temp= new node;
        cin>>temp->data;
        temp->next=head;
        head=temp;
    }

    return head;

}
void display(struct node *head)
{
    struct node *temp;

    temp=head;
    cout<<"\n List : ";
    for(int i=0;i<5;i++)
    {

       cout<<temp->data<<" ";
       temp=temp->next;

    }
}

//reversal using recurssion !

node *rev_using_rec(node *ne,node*pr)
{
    if(ne->next==NULL)
    {
        ne->next=pr;
        pr->next=NULL;
        return ne;
    }
    
    node *t=rev_using_rec(ne->next, ne);
    ne->next=pr;
    pr->next=NULL;
    return t;
}


node * rev_stack(struct node *head)
{
    struct node *temp;
    stack <int> s;
    temp=head;
    for(int i=4;i>=0;i--)
    {

       s.push(temp->data);
       temp=temp->next;

    }
    temp=head;
     for(int i=0;i<5;i++)
    {

       temp->data=s.top();
       temp=temp->next;
       s.pop();

    }
    return head;

}
int main()
{
    struct node n;

    struct node *head=nullptr;

    head=inputlist(head);
    display(head);
    head= rev_stack(head);
    display(head);
    return 0;
}
