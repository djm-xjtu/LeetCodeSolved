class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i < nums.size() && cnt < 2; i++){
            if(nums[i-1] <= nums[i]) continue;
            cnt++;
            if(i - 2 >= 0 && nums[i-2] > nums[i]){
                nums[i] = nums[i-1];
            }
            else nums[i-1] = nums[i];
        }
        return cnt < 2;
    }
};