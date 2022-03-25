class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        unordered_map<char, int> cache;
        int ans = 1;
        for(int i = 0; i < n; i++){
            cache.clear();
            cache[s[i]]++;
            int count = 1;
            for(int j = i + 1; j < n; j++){
                if(cache[s[j]] == 1){
                    ans = max(ans, count);
                    break;
                }
                count++;
                cache[s[j]] ++;
                if(j == n - 1) ans = max(ans, count);
            }
        }
        return ans;
    }
};