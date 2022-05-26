class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), cnt = 0, ans = 0;
        vector<int> sum(n+1, 0);
        for(int i = 1; i <= n; i++){
            sum[i] += sum[i-1] + nums[i-1];
            cnt += nums[i-1];
        }
        // cnt - n + i
        // 滑动窗口，维护一个长度为1的数量的窗口，统计窗口中1的数量，数量最多的就是答案
        for(int i = 0; i < n; i++){
            if(i + cnt - 1 < n){
                ans = max(ans, sum[i + cnt] - sum[i]);
            }
            else ans = max(ans, sum[n] - sum[i] + sum[cnt - n + i]);
        }
        return cnt - ans;
    }
};