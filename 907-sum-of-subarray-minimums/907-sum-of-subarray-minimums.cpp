typedef long long ll;
const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<ll> l(n, -1), r(n, n); //哨兵
        ll ans = 0;
        for(int i = 0; i < n; i++){
            while(stk.size() && arr[i] <= arr[stk.top()]){
                r[stk.top()] = i;
                stk.pop();
            }
            if(stk.size()) l[i] = stk.top();
            stk.push(i);
        }
        for(int i = 0; i < n; i++) ans = (ans + (i - l[i]) * (r[i] - i) * arr[i]) % MOD;
        return ans;
    }
};