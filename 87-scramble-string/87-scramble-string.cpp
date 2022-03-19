class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return 1;
        if(s1.size() != s2.size()) return 0;
        vector<int> c1(26), c2(26);
        int n = s1.size();
        for(int i = 0; i < n; i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(c1[i] != c2[i]) return 0;
        }
        bool dp[n][n][n+1];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s1[i] == s2[j]) dp[i][j][1] = 1;
            }
        }
        for(int k = 2; k <= n; k++){
            for(int i = 0; i <= n - k; i++){
                for(int j = 0; j <= n - k; j++){
                    for(int w = 1; w < k; w++){
                        dp[i][j][k] = dp[i][j][k] || dp[i][j][w] && dp[i+w][j+w][k-w] || dp[i][j+k-w][w] && dp[i+w][j][k-w];
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};