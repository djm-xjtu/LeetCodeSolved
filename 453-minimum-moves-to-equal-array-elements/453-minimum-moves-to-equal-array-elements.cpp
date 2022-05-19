class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0], cnt = 0;
        for(auto& i : nums){
            cnt += i;
            min_val = min(min_val, i);
        }
        return cnt - nums.size() * min_val;
    }
};