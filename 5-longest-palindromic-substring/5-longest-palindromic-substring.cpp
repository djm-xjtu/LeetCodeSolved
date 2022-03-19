class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return s;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
            int len1 = palin(s, i, i);
            int len2 = palin(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    
    int palin(string s, int l1, int r1){
        int n = s.size();
        int l = l1, r = r1;
        while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
        }
        return r - l - 1;
    }
};