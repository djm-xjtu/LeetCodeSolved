class Solution {
public:
    int maximalSquare(vector<vector<char>>& ma) {
        int n = ma.size(), m = ma[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        int max_val = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ma[i][j] == '1') f[i][j] = 1, max_val = max(max_val, 1);
                if(i < 1 || j < 1 || ma[i][j] == '0') continue;
                int t = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]);
                f[i][j] = t + 1;
                max_val = max(max_val, f[i][j] * f[i][j]);
            }
        }
        return max_val;
    }
};