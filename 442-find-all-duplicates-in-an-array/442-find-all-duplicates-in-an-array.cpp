class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        // > 2n
        for(int i = 0; i < n; i++){
            int x = (nums[i] - 1) % n;
            nums[x] += n;
            if(nums[x] > 2 * n) res.push_back(x + 1);
        }
        return res;
    }
};