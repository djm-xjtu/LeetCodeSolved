class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        arr1.insert(arr1.begin(), -1);
        sort(arr2.begin(), arr2.end());
        auto f(vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX)));
        f[0][0] = INT_MIN;
        for(int i = 1; i <= n; i++){
            for(int k = 0; k <= i; k++){
                if(arr1[i] > f[i-1][k]){
                    f[i][k] = min(f[i][k], arr1[i]);
                }
                if(k >= 1){
                    auto itr = upper_bound(arr2.begin(), arr2.end(), f[i-1][k-1]);
                    if(itr != arr2.end()) f[i][k] = min(f[i][k], *itr);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= n; i++){
            if(f[n][i] != INT_MAX)
                ans = min(ans, i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};