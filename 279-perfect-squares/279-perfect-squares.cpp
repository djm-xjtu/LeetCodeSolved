class Solution {
public:
    int numSquares(int n) {
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int j = 1; j <= n; j++){
            for(int i = 1; i * i <= j; i++){
                f[j] = min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
};