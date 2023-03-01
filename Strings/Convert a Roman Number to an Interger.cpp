
// program to convert a Roman number back to an interger !!!

#include<iostream>
using namespace std;

int value(char c)
{
    if(c == 'I')
        return 1;
    else if(c == 'V')
        return 5;
    else if(c == 'X')
        return 10;
    else if(c == 'L')
        return 50;
    else if(c == 'C')
        return 100;
    else if(c == 'D')
        return 500;
    else if(c == 'M')
        return 1000;
    return -1;
}

int convert(string s)
{
    int l=int(s.length());
    int ans=0,x,y;
    
    for(int i=0;i<l;i++)
    {
        if(i==l-1)
        {
            x=value(s[i]);
            ans+=x;
            return ans;
        }
        
        else
        {
            x=value(s[i]);
            y=value(s[i+1]);
            if(x>=y)
                ans+=x;
            else
                ans-=x;
        }
    }
    
    return ans;
}


int  main()
{
    cout<<convert("XXV");
}
