class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        f[0] = 1;
        int sum = 0, ans = 0;
        for(auto st : nums){
            sum += st;
            ans += f[sum - k];
            f[sum]++;
        }
        return ans;
    }
};