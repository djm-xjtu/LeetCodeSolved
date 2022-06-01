class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prerequisite(n, 0);
        for (const auto& pair : relations) {
            int pre = pair[0] - 1;
            int after = pair[1] - 1;
            prerequisite[after] |= 1<<pre;
        }

        int totalState = 1 << n;
        vector<int> dp(totalState, 16);
        dp[0] = 0;

        vector<int> cnt(totalState);
        cnt[0] = 0;
        for (int i = 1; i < totalState; ++i) {
            cnt[i] = cnt[i>>1] + (i&1);
        }

        for (int taken = 0; taken < totalState; ++taken) {
            if (dp[taken] > n) continue;
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                if (((taken & (1 << j)) == 0) && ((prerequisite[j] & taken) == prerequisite[j])) {
                    cur |= (1 << j);
                }
            }
            for (int subMask = cur; subMask != 0; subMask = subMask-1 & cur) {
                if (cnt[subMask] <= k) {
                    dp[taken|subMask] = min(dp[taken|subMask], dp[taken] + 1);
                }
            }
        }
        
        return dp[totalState - 1];
    }
};