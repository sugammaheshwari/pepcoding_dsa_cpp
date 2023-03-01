
// Q: Best time to buy and sell stock , infinite non overlapping transactions allowed (with a transaction fee)
// link : https://www.youtube.com/watch?v=pTQB9wbIpfU&t=802s


    int maxProfit(vector<int>& prices, int fee) {
        
        // pepcoding method !!
        
        int bp=0,sp=0;
        
        for(int i=0;i<prices.size();i++)
        {
            if(i==0)
            {
                bp=-1*prices[0];
                continue;
            }

            sp=max(sp,prices[i]+bp-fee);
            bp=max(bp,sp-prices[i]);
        }
        
        return sp;
    }


