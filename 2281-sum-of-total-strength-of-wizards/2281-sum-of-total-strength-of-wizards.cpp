const int mod = 1e9 + 7;
typedef long long ll;
class Solution {
public:
    int totalStrength(vector<int> &strength) {
        int n = strength.size();
        vector<int> left(n, -1); 
        vector<int> right(n, n); 
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && strength[i] <= strength[st.top()]) {
                right[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }
        vector<ll> s(n + 2);
        vector<ll> ss(n + 2);

        for(int i = 1; i <= n; i++){
            s[i + 1] = (s[i] + strength[i - 1]) % mod;
            ss[i + 1] = (ss[i] + s[i+1]) % mod;
        }
        // s[i] = (j = 0 : i - 1) strength[j];
        // [L, R]的所有前缀和的和是  (r = i + 1 : R + 1)(l = L : i)(s[r] - s[l]) //上限+1，下限不变
        // 推导得：(i - l + 1) * (ssum[i+1] - ssum[l]) + (r - i + 1) * (ssum[r+2] - ssum[i+1])
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll l = left[i] + 1, r = right[i] - 1; // [l,r] 左闭右闭
            ll cnt = ((i - l + 1) * (ss[r + 2] - ss[i + 1]) - (r - i + 1) * (ss[i + 1] - ss[l])) % mod;
            ans = (ans + strength[i] * cnt) % mod;
        }
        return (ans + mod) % mod;
    }
};