class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        //位上的1代表这个数是1～n行加的结果之一
        bitset<5000> f[n];
        f[0] = 0;
        for(int i = 0; i < m; i++)
            f[0][mat[0][i]] = 1;
        for(int i = 1; i < n; i++){
            f[i] = 0;
            //计算上一行+本行的所有情况，且可以自动去重
            for(int j = 0; j < m; j++){
                f[i] |= f[i - 1] << mat[i][j];
            }
        }
        int ans = 6000;
        for(int i = 1; i <= 5000; i++){
            if(f[n-1][i])
                ans = min(ans, abs(target - i));
        }
        return ans;
    }
};