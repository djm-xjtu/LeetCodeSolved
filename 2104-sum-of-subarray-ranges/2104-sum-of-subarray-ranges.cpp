typedef long long ll;
class Solution {
public:
    ll solve(vector<int>& nums){
        ll ans = 0;
        int n = nums.size();
        stack<int> stk;
        vector<int> l(n, -1);
        vector<int> r(n, n);
        for(int i = 0; i < n; i++){
            while(stk.size() && nums[i] >= nums[stk.top()]){
                int t = stk.top();
                stk.pop();
                r[t] = i;
            }
            if(stk.size()) l[i] = stk.top();
            stk.push(i);
        }
        for(int i = 0; i < n; i++){
            ans += 1ll*(r[i] - i) * (i - l[i]) * nums[i];
        }
        while(!stk.empty()) stk.pop();
        l.clear();//resize指定值，之前必须清空
        r.clear();
        l.resize(n, -1);
        r.resize(n, n);
        for(int i = 0; i < n; i++){
            while(stk.size() && nums[i] <= nums[stk.top()]){
                int t = stk.top();
                stk.pop();
                r[t] = i;
            }
            if(stk.size()) l[i] = stk.top();
            stk.push(i);
        }
        ll res = 0;
        for(int i = 0; i < n; i++){
            res += 1ll*(r[i] - i) * (i - l[i]) * nums[i];
        }
        return ans - res;
    }
    ll subArrayRanges(vector<int>& nums) {
        ll ans = solve(nums);
        //可以分别计算一个位最大值贡献和最小值贡献再减
        //或者把每一位取反
        //for(int i = 0; i < nums.size(); i++) nums[i] = -nums[i];
        //ans += solve(nums);
        return ans;
    }
};