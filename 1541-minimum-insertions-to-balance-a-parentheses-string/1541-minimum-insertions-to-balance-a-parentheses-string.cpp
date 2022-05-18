class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0, ans = 0;
        for (auto ch : s) {
            if (ch == '(') {
                cnt += 2;
                if (cnt % 2 == 1) {
                    ans++;
                    cnt--;
                }
            } else {
                if (cnt == 0) {
                    ans++;
                    cnt = 1;
                } else {
                    cnt--;
                }
            }
        }
        ans += cnt;
        return ans;
    }
};