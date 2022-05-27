class Solution {
public:
    vector<int> cur;
    vector<int> cnt;
    int mask1 = 0, mask2 = 0;
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), k = 0, len = INT_MAX;
        cur.resize(150);
        cnt.resize(150);
        string ans = "";
        if(n < m) return ans;
        for(char c : t){
            cnt[c]++;
            if(c >= 'a' && c <= 'z') mask1 |= (1 << (c - 'a'));
            else mask2 |= (1 << (c - 'A'));
        }
        int l = 0, r = 0;
        while(r < n){
            //覆盖
            while(r < n && !check()){
                cur[s[r++]]++;
            }
            //缩小，取值
            while(l < n && check()){
                if(r - l < len) ans = s.substr(l, r - l), len = r - l;
                cur[s[l++]]--;
            }
        }
        return ans;
    }
    bool check(){
        for(int i = 0; i < 26; i++){
            if(mask1 & (1 << i)){
                if(cur[i + 'a'] < cnt[i + 'a']) return false;
            }
            if(mask2 & (1 << i)){
                if(cur[i + 'A'] < cnt[i + 'A']) return false;
            }
        }
        return true;
    }
};