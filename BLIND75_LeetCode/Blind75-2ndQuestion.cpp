//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

//121. Best Time to Buy and Sell Stock

int maxProfit(vector<int>& prices) {
        int curr_profit=0,min_price=INT_MAX,max_profit=0;
        for(int i=0;i<prices.size();i++){
            curr_profit=prices[i]-min_price;
            max_profit=max(curr_profit,max_profit);
            min_price=min(min_price,prices[i]);
        }
        return max_profit;
    }