class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn=INT_MAX;
        int maxx=INT_MIN;
        int profit=0;
        for (int i =0; i<prices.size(); i++){
            if(prices[i]<minn){
                minn=prices[i];
                maxx=0;
            }
            else if(prices[i]>maxx){
                maxx=prices[i];
            }
            profit=max(profit,maxx-minn);
        }
        return profit;
    }
};