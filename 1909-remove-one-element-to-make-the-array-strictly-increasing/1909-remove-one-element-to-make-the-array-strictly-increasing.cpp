class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>> f(n+1, vector<int>(2, INT_MAX));
        f[0][0] = 0;
        f[0][1] = 0;
        for(int i = 1; i <= n; i++){
            for(int k = 0; k < 2; k++){
                if(f[i-1][k] < nums[i]){
                    f[i][k] = min(f[i][k], nums[i]);
                }
                if(k > 0){
                    f[i][k] = min(f[i][k], f[i-1][k-1]);
                }
            }
        }
        return f[n][1] != INT_MAX;
    }
};