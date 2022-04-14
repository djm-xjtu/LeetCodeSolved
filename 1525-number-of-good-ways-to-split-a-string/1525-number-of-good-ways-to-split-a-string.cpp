class Solution {
public:
    unordered_map<char, int> p1;
    unordered_map<char, int> p2;
    int numSplits(string s) {
        int n = s.size();
        int res1 = 0;
        int res2 = 0; // 多次出现
        int ans = 0;
        for(int i = 0; i < n; i++) {
            p2[s[i]]++;
            if(p2[s[i]] >= 2) res2++;
        }
        for(int i = 1; i < n; i++){
            p1[s[i-1]]++;
            p2[s[i-1]]--;
            if(p1[s[i-1]] >= 2) res1++;
            if(p2[s[i-1]] >= 1) res2--;
            if(i - res1 == n - i - res2) ans++;
        }
        return ans;
    }
};