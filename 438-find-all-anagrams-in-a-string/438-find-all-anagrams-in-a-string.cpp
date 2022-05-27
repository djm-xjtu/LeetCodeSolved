class Solution {
public:
    bool check(int h[], int t[]){
        for(char i = 0; i < 26; i++){
            if(h[i] != t[i]) return false;
        }
        return true;
    }
    int h[26], t[26];
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(m > n) return {};
        vector<int> res;
        for(int i = 0; i < m; i++) h[p[i] - 'a']++;
        for(int i = 0, j = 0; i < n; i++){
            t[s[i] - 'a']++;
            if(i - j + 1 > m){
                t[s[j++] - 'a']--;
            }
            if(check(h, t)) res.push_back(j);
        }
        return res;
    }
};