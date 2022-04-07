class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> h;
        int s = 0, res = 0;
        h[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            if(nums[i - 1] == 0) s += -1;
            else s += 1;
            if(h.find(s) != h.end()) res = max(res, i - h[s]);
            else h[s] = i;
        }
        return res;
    }
};