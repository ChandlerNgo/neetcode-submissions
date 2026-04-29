class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // min prefix array
        // max suffix arrray

        int minVal = prices[0];
        vector<int> prefixMin;
        for(int i = 0; i < prices.size(); i++){
            minVal = min(prices[i],minVal);
            prefixMin.push_back(minVal);
        }
        int maxVal = prices[prices.size()-1];
        vector<int> suffixMax;
        for(int i = prices.size()-1; i >= 0; i--){
            maxVal = max(prices[i],maxVal);
            suffixMax.push_back(maxVal);
        }

        reverse(suffixMax.begin(), suffixMax.end());

        int profit = 0;
        for(int i = 0; i < prefixMin.size()-1; i++){
            profit = max(profit, suffixMax[i+1]-prefixMin[i]);
        }
        return profit;
    }
};
