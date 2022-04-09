class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> h;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            h[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            int l = nums[i] - 1, r = nums[i] + 1;
            while(h[l]) h[l] = 0, l--;
            while(h[r]) h[r] = 0, r++;
            res = max(res, r - l - 1);
        }
        return res;
    }
};