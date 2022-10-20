class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int f[n+1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        s = " " + s;
        for(int i = 1; i <= n; i++){
            if(s[i] != '0') {
                f[i] = f[i-1];
            }
            if(i > 1 && s[i-1] - '1' == 0){
                f[i] += f[i-2];
            }
            else if(i > 1 && s[i-1] - '2' == 0 && s[i] < '7'){
                f[i] += f[i-2];
            }
        }
        return f[n];
    }
};