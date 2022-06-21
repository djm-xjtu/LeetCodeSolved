int graph[10][3] = {{4,6, -1},{6,8, -1},{7,9, -1},{4,8, -1},{3,9,0},{-1, -1, -1},{1,7,0},{2,6, -1},{1,3, -1},{2,4, -1}};
const int mod = 1e9+7;
class Solution {
public:
    int dfs(vector<vector<int>>& memo, int cur, int n){
        if(n == 0) return 1;
        if(memo[cur][n] != -1) return memo[cur][n];
        long long t = 0;
        for(auto i : graph[cur]){
            if(i != -1)
                t = (t + dfs(memo, i, n - 1)) % mod;
        }
        memo[cur][n] = t;
        return t;
    }
    int knightDialer(int n) {
        vector<vector<int>> memo(10, vector<int>(n, -1));
        long long ans = 0;
        for(int i = 0; i < 10; i++){
            ans = (ans + dfs(memo, i, n - 1)) % mod;
        }
        return ans;
    }
};