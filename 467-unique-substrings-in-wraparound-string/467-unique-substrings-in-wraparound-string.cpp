class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> f(26);
        int tem = 1, ans = 0;
        f[p[0] - 'a'] = 1;
        for(int i = 1; i < n; i++){
            if((p[i] - p[i-1] + 26) % 26 == 1) ++tem;
            else tem = 1;
            f[p[i] - 'a'] = max(f[p[i] - 'a'], tem); 
        }
        for(int i = 0; i < 26; i++) ans += f[i];
        return ans;
    }
};