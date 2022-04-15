class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int f[510][510];
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(word1[i-1] == word2[j-1]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
        }
        return n1 + n2 - 2 * f[n1][n2];
    }
};