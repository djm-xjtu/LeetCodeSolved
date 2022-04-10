class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int f[310][310];
        memset(f, 0, sizeof f);
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int u = i + 1, v = j + 1;
                if(matrix[i][j] == '1') {
                    f[u][v] = min(f[u-1][v-1], min(f[u][v-1], f[u-1][v])) + 1;
                    ans = max(ans, f[u][v] * f[u][v]);
                }
                cout << f[u][v] << " ";
            }
            cout << "\n";
        }
        
        return ans;
    }
};