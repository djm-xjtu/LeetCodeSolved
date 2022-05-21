const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        vector<int> f(2, 0);
        //zero用于补上"0"这种情况
        int zero = 0, n = binary.size();
        for(int i = n - 1; i >= 0; i--){
            int t = binary[i] - '0';
            if(t == 0) zero = 1;
            f[t & 1] = (f[0] + f[1] + 1) % MOD;
        }
        int ans = (f[1] + zero) % MOD;
        return ans;
    }
};