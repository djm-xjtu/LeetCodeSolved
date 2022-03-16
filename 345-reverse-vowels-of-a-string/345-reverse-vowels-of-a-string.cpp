class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        unordered_map<char, int> cache;
        cache['a'] = 1, cache['e'] = 1, cache['i'] = 1, cache['o'] = 1, cache['u'] = 1;
        cache['A'] = 1, cache['E'] = 1, cache['I'] = 1, cache['O'] = 1, cache['U'] = 1;
        while(l < r){
            char a = s[l], b = s[r];
            if(cache[a] == 1 && cache[b] == 1){
                char i = s[l];
                s[l] = s[r];
                s[r] = i;
                l++;
                r--;
            }
            else if(cache[a]) r--;
            else if(cache[b]) l++;
            else l++, r--;
        }
        return s;
    }
};