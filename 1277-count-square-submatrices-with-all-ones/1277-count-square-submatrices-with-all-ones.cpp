class Solution {
public:
    int countSquares(vector<vector<int>>& ma) {
        int n = ma.size(), m = ma[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    if(ma[i][j] == 1) f[i][j] = 1, cnt++;
                    continue;
                }
                if(ma[i][j] == 0) continue;
                int t = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
                f[i][j] = t;
                cnt += f[i][j];
            }
        }
        return cnt;
    }
};