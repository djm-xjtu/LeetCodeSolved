class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int min_val = 1e6;
        for(int i = 0; i < n; i++){
            min_val = min(min_val, prices[i]);
            ans = max(ans, prices[i] - min_val);
        }
        return ans;
    }
};