const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string c) {
        int n = c.size();
        int cnt = 0;
        long long num = 0;
        vector<long long> v;
        for (int i = 0; i < n; ++i) {
            if (c[i] == 'S') {
                if (cnt == 2) {
                    v.push_back(num);
                    num = 0;
                    cnt = 1;
                } else {
                    ++cnt;
                }
            } else {
                if (cnt == 2) {
                    ++num;
                }
            }
        }
        if (cnt == 1) return 0;
        if (v.size() == 0) {
            if (cnt == 2) {
                return 1;
            } else {
                return 0;
            }
        }
        int ans = 1;
        for (int i = 0; i < v.size(); ++i) {
            ans = 1LL * ans * (v[i] + 1) % MOD;
        }
        return ans;
    }
};