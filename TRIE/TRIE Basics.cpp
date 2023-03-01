
// TRIE DATA STRUCTURES !!!

#include<iostream>
#include<vector>
using namespace std;

struct node{
    int word_end;
    vector<node*> child;
    
    node()
    {
        word_end=0;
        child=vector<node*> (26,NULL);
    }
    
};

node *ROOT=new node();

// function to insert into our TRIE data structure !!!
void insert(string str)
{
    node *curr=ROOT;
    int n=int(str.length());
    
    for(int i=0;i<n;i++)
    {
        int idx=str[i]-'a';
        if(curr->child[idx]==NULL)
        {
            curr->child[idx]=new node();
        }
        curr=curr->child[idx];
    }
    curr->word_end++;
}

// function to search for the passed string str
bool search(string str)
{
    node *curr=ROOT;
    int n=int(str.length());
    
    for(int i=0;i<n;i++)
    {
        int idx=str[i]-'a';
        curr=curr->child[idx];
        if(curr==NULL)
            return false;
    }
    
    return curr->word_end>0?true:false;
}

// function to find if prefix exists or not !!
bool startsWith(string str)
{
    node *curr=ROOT;
       int n=int(str.length());
       
       for(int i=0;i<n;i++)
       {
           int idx=str[i]-'a';
           curr=curr->child[idx];
           if(curr==NULL)
               return false;
       }
       
    return true;
}
