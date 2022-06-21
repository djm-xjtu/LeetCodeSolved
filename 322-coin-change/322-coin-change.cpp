class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int f[amount+1], n = coins.size();
        for(int i = 0; i <= amount; i++)
            f[i] = INT_MAX / 2;
        f[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                f[j] = min(f[j], f[j-coins[i]] + 1);
            }
        }
        return f[amount] == INT_MAX / 2 ? -1 : f[amount];
    }
};