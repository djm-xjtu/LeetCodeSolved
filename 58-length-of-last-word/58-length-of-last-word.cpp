class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int t = 0;
        bool f = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ' ') continue;
            if(f) break;
            while(i >= 0 && s[i] != ' '){
                i--;
                t++;
                f = 1;
            }
        }
        return t;
    }
};