class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nn = strs.size();
        unordered_map<int, pair<int, int>> h;
        for(int i = 0; i < nn; i++){
            int zero = 0, one = 0;
            for(auto j : strs[i]){
                if(j == '0') zero++;
                if(j == '1') one++;
            }
            h[i] = {zero, one};
        }
        int f[m+1][n+1];
        memset(f, 0, sizeof f);
        for(int i = 0; i < nn; i++){
            for(int j = m; j >= h[i].first; j--){
                for(int k = n; k >= h[i].second; k--){
                    f[j][k] = max(f[j][k], f[j-h[i].first][k-h[i].second] + 1);
                }
            }
        }
        return f[m][n];
    }
};