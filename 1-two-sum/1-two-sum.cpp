class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        for(int i = 0; i < nums.size(); i++){
            if(!cache[target - nums[i]]) cache[nums[i]] = i + 1;
            else{
                return {cache[target - nums[i]] - 1, i};
            }
        }
        return {0, 0};
    }
};