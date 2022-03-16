class Solution {
public:
    bool validPalindrome(string s) {
        int count = 1;
        int l = 0, r = s.size() - 1;
        bool f1 = 1, f2 = 1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
                continue;
            }
            if(count == 1){
                count--;
                l++;
                continue;
            }
            f1 = 0;
            break;
        }
        l = 0, r = s.size() - 1, count = 1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
                continue;
            }
            if(count == 1){
                count--;
                r--;
                continue;
            }
            f2 = 0;
            break;
        }
        cout << f1 << f2;
        return f1 || f2;
    }
};