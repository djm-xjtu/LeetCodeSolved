class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            cache[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            int t = target - nums[i];
            cache[nums[i]]--;
            if(cache[t]){
                for(int j = n-1; j >= 0; j--){
                    if(nums[j] == t) return{i, j};
                }
            }
        }
        return {};
    }
};