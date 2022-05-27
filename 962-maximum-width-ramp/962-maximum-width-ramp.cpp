class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0, n = nums.size();
        stack<int> stk;
        // 计算两数差大于0的最长距离的统一做法
        // 维护递减栈是因为如果后面数比前面数大，那么它和后面数的距离小，而且数量大，不如栈顶数优
        for(int i = 0; i < n; i++){
            while(stk.empty() || nums[i] < nums[stk.top()]){
                stk.push(i);
            }
        }
        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && nums[i] >= nums[stk.top()]){
                ans = max(ans, i - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};