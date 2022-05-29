class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int res = 0, n = nums.size();
        stack<int> stk;
        //消除第i个数需要几轮
        vector<int> f(n+1);
        for(int i = 0; i < n; i++){
            int cur = 0;
            //找左边第一个比它大的数
            //统计两个数之间的数全部消除需要的轮数
            while(!stk.empty() && nums[stk.top()] <= nums[i]){
                cur = max(f[stk.top()], cur);
                stk.pop();
            }
            //如果左边比它大的数存在
            if(stk.size()){
                //答案为轮数+1
                res = max(res, cur + 1);
                f[i] = cur + 1;
            }
            stk.push(i);
        }
        return res;
    }
};