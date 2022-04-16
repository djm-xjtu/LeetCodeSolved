class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool f[n+1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for(int i = 1; i <= n; i++){
            for(auto t : wordDict){
                if(t.size() <= i && s.substr(i - t.size(), t.size()) == t){
                    f[i] = f[i] || f[i - t.size()];
                }
            }
        }
        return f[n];
    }
};