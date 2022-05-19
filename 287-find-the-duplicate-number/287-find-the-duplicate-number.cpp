class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            int x = abs(nums[i]) - 1;
            if(nums[x] < 0){
                return x + 1;
            }
            nums[x] = -nums[x];
        }
        return -1;
    }
};