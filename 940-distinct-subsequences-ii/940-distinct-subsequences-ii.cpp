class Solution {
public:
    int distinctSubseqII(string s) {
        long long f[2010], n = s.size(), mod = 1e9 + 7;
        memset(f, 0, sizeof f);
        f[0] = 1;
        int last[26];
        for(int i = 0; i < 26; i++) last[i] = -1;
        for(int i = 1; i <= n; i++){
            f[i] = 2*f[i-1]; 
            int cur = last[s[i-1] - 'a'];
            if(cur >= 0){
                f[i] -= f[cur];
            }
            f[i] = (f[i] + mod) % mod; //安全取模
            last[s[i-1] - 'a']  = i - 1;
            cout << f[i] - 1<< endl;
        }
        return (f[n] - 1 + mod) % mod;
    }
};