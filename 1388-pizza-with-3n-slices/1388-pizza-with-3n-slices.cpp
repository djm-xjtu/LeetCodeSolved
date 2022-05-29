class Solution {
public:
    int helper(vector<int>& slices, int l, int r, int k){
        int n = slices.size();
        vector<vector<int>> f(k + 1, vector<int>(2));
        for(int i = l; i <= r; i++){
            for(int j = min(k, i - l + 1); j >= 1; j--){
                f[j][0] = max(f[j][0], f[j][1]);
                f[j][1] = f[j-1][0] + slices[i-1];
            }
        }
        return max(f[k][0], f[k][1]);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        return max(helper(slices, 1, n - 1, n / 3), helper(slices, 2, n, n / 3));
    }
};