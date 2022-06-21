class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int f[sum / 2 + 1];
        //target = sum - 2 * sum(p)
        //转化问题为从stones[]中装入sum / 2的背包的最大值
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++){
            for(int j = sum / 2; j >= stones[i]; j--){
                f[j] = max(f[j], f[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * f[sum / 2];
    }
};