class Solution {
public:
    int mod = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        //经典DP模型，前i个数，拿出j个数，价值（随题意而定）为k
        int n = arr.size(), mod = 1e9 + 7;
        int f[n+1][4][target+1];
        memset(f, 0, sizeof f);
        for(int i = 0; i <= n; i++) f[i][0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                for(int k = 0; k <= target; k++){
                    //用第i个数，从i-1状态少取一个数，并且价值加上第i个数的价值
                    if(arr[i-1] <= k) f[i][j][k] = (f[i][j][k] + f[i-1][j-1][k-arr[i-1]]) % mod;
                    //不用第i个数
                    f[i][j][k] = (f[i][j][k] + f[i-1][j][k]) % mod;
                }
            }
        }
        return f[n][3][target];
    }
};