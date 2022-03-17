class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_val[n];
        int ans = 0;
        memset(max_val, 0, sizeof max_val);
        max_val[n-1] = prices[n-1];
        for(int i = n - 2; i >= 0; i--){
            max_val[i] = max(max_val[i+1], prices[i]);
        }
        for(int i = 0; i < n-1; i++){
            ans = max(ans, max_val[i] - prices[i]);
        }
        return ans;
    }
};