class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> gain(10010);
        for(int num : nums)
            gain[num] += num;
        int n = gain.size();
        vector<int> f(n);
        f[1] = gain[1];
        for(int i = 2; i < n; i++){
            f[i] = max(f[i-1], f[i-2] + gain[i]);
        }
        return f[n-1];
    }
};