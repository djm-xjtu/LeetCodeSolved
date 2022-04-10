class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());

        vector<int> f(n), g;
        g.push_back(0);

        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (envelopes[i][0] != envelopes[j][0]) {
                while (j < i) {
                    if (f[j] == g.size())
                        g.push_back(envelopes[j][1]);
                    else
                        g[f[j]] = min(g[f[j]], envelopes[j][1]);
                    j++;
                }
            }

            int l = 0, r = g.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (envelopes[i][1] <= g[mid])
                    r = mid;
                else
                    l = mid + 1;
            }

            f[i] = l;
            ans = max(ans, f[i]);
        }

        return ans;
    }
};