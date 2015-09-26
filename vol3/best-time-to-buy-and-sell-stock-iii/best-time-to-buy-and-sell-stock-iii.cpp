class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        
        int n = prices.size();
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        int minP = prices[0];
        for(int i = 1; i < n; ++ i) {
            minP = min(minP, prices[i]);
            l[i] = max(l[i - 1], prices[i] - minP);
        }
        int maxP = prices[n - 1], ret = 0;
        for(int i = n - 2; i >= 0; -- i) {
            maxP = max(maxP, prices[i]);
            r[i] = max(r[i + 1], maxP - prices[i]);
            ret = max(ret, l[i] + r[i]);
        }
        return ret;
    }
};