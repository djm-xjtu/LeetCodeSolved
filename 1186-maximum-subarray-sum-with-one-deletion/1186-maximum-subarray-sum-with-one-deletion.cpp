class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int f[n][2], ans = arr[0];
        memset(f, 0, sizeof f);
        f[0][0] = arr[0];
        f[0][1] = 0;
        for(int i = 1; i < n; i++){
            f[i][0] = max(f[i-1][0] + arr[i], arr[i]);
            f[i][1] = max(f[i-1][1] + arr[i], f[i-1][0]);
            ans = max(ans, max(f[i][0], f[i][1]));
        }
        return ans;
    }
};