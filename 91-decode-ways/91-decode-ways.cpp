class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        s = " " + s;
        for(int i = 1; i <= n; i++){
            if(s[i] != '0') f[i] += f[i-1];
            if(i > 1){
                int t = (s[i-1] - '0')*10 + s[i] - '0';
                if(t >= 10 && t <= 26) f[i] += f[i-2];
            }
        }
        return f[n];
    }
};