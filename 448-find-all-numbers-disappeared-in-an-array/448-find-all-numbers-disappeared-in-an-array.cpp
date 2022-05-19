class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        //原地哈希
        for(int i = 0; i < n; i++){
            int x = (nums[i] - 1) % n;
            nums[x] += n;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] <= n) res.push_back(i + 1);
        }
        return res;
    }
};