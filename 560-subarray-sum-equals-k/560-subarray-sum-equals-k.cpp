class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> h;
        int s = 0;
        h[0] = 1;
        for(auto i : nums){
            s += i;
            res += h[s - k];
            h[s]++;
        }
        return res;
    }
};