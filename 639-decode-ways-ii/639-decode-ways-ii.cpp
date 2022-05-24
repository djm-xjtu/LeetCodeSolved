const int mod = 1e9 + 7;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n+1);
        f[0] = 1;
        s = " " + s;
        for(int i = 1; i <= n; i++){
            long long cnt = 0;
            for(int c = 1; c <= 9; c++){
                if(s[i] == '*' || s[i] == c + '0'){
                    cnt += f[i-1];
                }
            }
            for(int c = 10; c <= 26; c++){
                if(i == 1) break;
                int a = c / 10, b = c % 10;
                char pre = s[i-1];
                if(pre == '0') break;
                if(pre == '*' || pre == a + '0'){
                    if((s[i] == '*' && b != 0) || (s[i] == b + '0')){
                        cnt += f[i-2];
                    }
                }
            }
            f[i] = cnt % mod;
        }
        return f[n];
    }
};