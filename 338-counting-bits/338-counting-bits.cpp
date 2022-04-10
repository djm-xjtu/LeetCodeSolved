class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n + 1);
        for(int i = 1; i <= n; i++){
            f[i] = f[i / 2] + (i & 1);
        }
        return f;
    }
};