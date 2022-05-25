class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> h;
        vector<long long> f(n, 1);
        long long cnt = 0;
        for(int i = 0; i < n; i++) h[arr[i]] = i;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    if(h.count(arr[i] / arr[j])) f[i] += f[j] * f[h[arr[i] / arr[j]]];
                }
            }
            cnt = (cnt + f[i]) % mod;
        }
        return cnt;
    }
};