class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        set<char> cache;
        cache.insert('a'),cache.insert('e'),cache.insert('i'),cache.insert('o'),cache.insert('u');
        cache.insert('A'),cache.insert('E'),cache.insert('I'),cache.insert('O'),cache.insert('U');
        while(l < r){
            char a = s[l], b = s[r];
            if(cache.count(a) == 1 && cache.count(b) == 1){
                char i = s[l];
                s[l] = s[r];
                s[r] = i;
                l++;
                r--;
            }
            else if(cache.count(a)) r--;
            else if(cache.count(b)) l++;
            else l++, r--;
        }
        return s;
    }
};