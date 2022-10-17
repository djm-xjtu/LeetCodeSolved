class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int Max = 1;
        int len = 1;
        for(int i = 0; i < n; i++){
            int l = i - 1, r = i + 1;
            while(l >= 0 && s[i] == s[l]){
                l--;
                len++;
            }
            while(r < n && s[i] == s[r]){
                r++;
                len++;
            }
            while(l >= 0 && r < n && s[l] == s[r]){
                l--, r++;
                len += 2;
            }
            if(len >= Max){
                l++;
                ans = s.substr(l, len);
                Max = len;
            }
            len = 1;
        }
        return ans;
    }
};