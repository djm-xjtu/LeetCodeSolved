class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int f[amount+1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                f[j] += f[j-coins[i]];
            }
        }
        return f[amount];
    }
};