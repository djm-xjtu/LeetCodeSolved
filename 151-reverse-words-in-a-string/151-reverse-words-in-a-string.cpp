class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int k = 0;
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && s[j] == ' ') j++;
            if(j == n) break;
            i = j;
            while(j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            if(k) s[k++] = ' ';
            while(i < j) s[k++] = s[i++];
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};