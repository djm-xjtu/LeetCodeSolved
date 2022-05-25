class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> f(n+1, 0);
        for(int i = n - 1; i >= 0; i--){
            auto p = questions[i];
            f[i] = max(f[i+1], f[(i + 1 + p[1] >= n ? 0 : i + 1 + p[1])] + p[0]);
        }
        return f[0];
    }
};