const int mod = 1e9 + 7;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> f(n);
        stack<int> stk;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long sum = 0;
            while(stk.size() && nums[i] < nums[stk.top()]){
                int t = stk.top();
                stk.pop();
                sum += f[t];
                ans = max(ans, sum * nums[t]);
            }
            stk.push(i);
            f[i] = sum + nums[i];
        }
        long long sum = 0;
        while(stk.size()){
            int t = stk.top();
            stk.pop();
            sum += f[t];
            ans = max(ans, sum * nums[t]);
        }
        return ans % mod;
    }
};