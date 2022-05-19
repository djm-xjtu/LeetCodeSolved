class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_val = nums[0], cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            cnt += nums[i] - min_val;
        }
        return cnt;
    }
};