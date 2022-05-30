class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> f;
        for(int i = 0; i < n; i++){
            f[arr[i]].push_back(i);
        }
        for(auto[x, y] : f){
            int len = y.size();
            vector<long long> l(len);
            vector<long long> r(len);
            for(int i = 1, j = len - 2; i < len; i++, j--){
                //O(1)地算出每个数字左边数对它的贡献和右边数字对它的贡献
                //如果每次循环只+1，那么TC是O(N^2)，所以这类题都必须用数学运算解决
                l[i] = l[i-1] + i * (y[i] - y[i-1]);
                r[j] = r[j+1] + (len - j - 1) * (y[j + 1] - y[j]);
            }
            for(int i = 0; i < len; i++)
                ans[y[i]] = l[i] + r[i];
        }
        return ans;
    }
};