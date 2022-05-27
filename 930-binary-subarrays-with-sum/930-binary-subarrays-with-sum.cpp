class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ans = 0;
        vector<int> h(30001);
        h[0] = 1;
        int sum = 0;
        //统计和数量也可以用hash。。
        //Leetcode 523，560，974，525，1124，528，497，1248，930
        for(auto st : nums){
            sum += st;
            if(sum - goal >= 0)
                ans += h[sum - goal];
            h[sum]++;
        }
        return ans;
    }
};