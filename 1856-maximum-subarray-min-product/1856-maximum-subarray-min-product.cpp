const int mod = 1e9 + 7;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        //加两个哨兵
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
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
        cout << stk.size();
        //或者最后处理没有出栈的元素
        while(stk.size()){
            int t = stk.top();
            stk.pop();
            sum += f[t];
            ans = max(ans, sum * nums[t]);
        }
        return ans % mod;
    }
};