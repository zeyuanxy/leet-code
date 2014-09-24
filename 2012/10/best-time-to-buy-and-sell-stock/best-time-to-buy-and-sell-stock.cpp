class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        int maxPrice = prices[n - 1];
        int maxProfit = 0;
        for(int i = n - 2; i >= 0; i --)
        {
            if(maxPrice - prices[i] > maxProfit)
                maxProfit = maxPrice - prices[i];
            if(maxPrice < prices[i])
                maxPrice = prices[i];
        }
        return maxProfit;
    }
};