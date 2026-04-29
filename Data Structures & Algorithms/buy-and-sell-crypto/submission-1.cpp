class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            minVal = min(minVal, prices[i]);
            profit = max(profit,prices[i]-minVal);
        }
        return profit;
    }
};
