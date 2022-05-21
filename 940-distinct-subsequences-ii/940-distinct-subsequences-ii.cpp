const int mod = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> f(26);
        long long res = 0;
        for(int i = 0; i < n; i++){
            int t = s[i] - 'a';
            long long cnt = 0;
            for(int j = 0; j < 26; j++){
                cnt += f[j];
                cnt = cnt % mod;
            }
            //接在以前的所有子序列后面：cnt，不接在任何子序列后面，自己形成一个子序列
            f[t] = (cnt + 1) % mod;
        }
        for(int i = 0; i < 26; i++){
            res += f[i];
            res %= mod;
        }
        return res;
    }
};