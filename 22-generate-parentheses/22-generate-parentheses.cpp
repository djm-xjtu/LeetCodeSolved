class Solution {
public:
    vector<string> res;
    void solve(int l, int r, int n, string cur) {
        if (l == n && r == n) {
            res.push_back(cur);
            return;
        }
        if (l < n)
            solve(l + 1, r, n, cur + "(");

        if (r < l)
            solve(l, r + 1, n, cur + ")");
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return res;
        solve(0, 0, n, "");
        return res;
    }
};