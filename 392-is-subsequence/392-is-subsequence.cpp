class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n > m) return 0;
        int idx = 0;
        for(int i = 0; i < m; i++){
            if(s[idx] == t[i]) idx++;
        }
        if(idx == n) return 1;
        return 0;
    }
};