class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(') l++;
            if(l == 0 && s[i] == ')') r++;
            else if(s[i] == ')') l--;
        }
        dfs(s, 0, l, r);
        return res;
    }
    bool check(string s){
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') count++;
            if(s[i] == ')') count--;
            if(count < 0) return 0;
        }
        return count == 0;
    }
    void dfs(string s, int u, int l, int r){
        if(l == 0 && r == 0){
            if(check(s)) res.push_back(s);
            return;
        }
        int n = s.size();
        for(int i = u; i < n; i++){
            if(s[i] != '(' && s[i] != ')') continue;
            if(i == u || s[i-1] != s[i]){
                string cur = s;
                cur.erase(i, 1);
                if(s[i] == '(' && l > 0) dfs(cur, i, l - 1, r);
                else if(s[i] == ')' && r > 0) dfs(cur, i, l, r - 1);
            }
        }
    }
};