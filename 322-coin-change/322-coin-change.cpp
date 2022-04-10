class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int f[10010];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }
        if(f[amount] == 0x3f3f3f3f) return -1;
        else return f[amount];
    }
};