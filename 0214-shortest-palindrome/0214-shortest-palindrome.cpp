class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> next(n, 0);
        int j = 0;
        for(int i = 2; i < n; i++){
            while(j > 0 && s[i - 1] != s[j]){
                j = next[j];
            }
            if(s[i-1] == s[j]){
                j++;
            }
            next[i] = j;
        }
        j = 0;
        //匹配最长回文前缀
        for(int i = n - 1; i >= 0; i--){
            while(j > 0 && s[i] != s[j]){
                j = next[j];
            }
            if(s[i] == s[j]){
                j++;
            }
        }
        string ans = s.substr(j);
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
};