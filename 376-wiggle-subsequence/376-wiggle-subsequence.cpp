class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int p = 1, q = 1;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] < nums[i]) 
                p = q + 1;
            if(nums[i - 1] > nums[i])
                q = p + 1;
        }
        return max(p, q);
    }
};