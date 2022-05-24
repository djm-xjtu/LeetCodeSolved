const int mod = 1e9 + 7;
class Solution {
public:
    int countTexts(string p) {
        int n = p.size();
        vector<int> f(n+1);
        p = ' ' + p;
        f[0] = 1;
        for(int i = 1; i <= n; i++){
            f[i] = f[i-1];
            if(i >= 2 && p[i-1] == p[i])
                f[i] = (f[i] + f[i-2]) % mod;
            if(i >= 3 && p[i-2] == p[i-1] && p[i-2] == p[i])
                f[i] = (f[i] + f[i-3]) % mod;
            if(i >= 4 && p[i-3] == p[i-2] && p[i-3] == p[i-1] && p[i-3] == p[i] && (p[i] == '7' || p[i] == '9'))
                f[i] = (f[i] + f[i-4]) % mod;
        }
        return f[n];
    }
};