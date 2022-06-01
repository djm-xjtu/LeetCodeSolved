class Solution {
public:
    //计算max的dfs+backtrack 比方法二剪掉了一些不可能的情况
    //同时也可以用状态压缩brute force 
    int n;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        for(char c : letters) cnt[c-'a']++;
        return dfs(cnt, 0, 0, words, score);
    }
    int dfs(int cur[], int idx, int sum, vector<string>& words, vector<int>& sc){
        if(idx == n){
            return sum;
        }
        int ans = dfs(cur, idx + 1, sum, words, sc);
        int curr[26];
        memcpy(curr, cur, sizeof curr);
        for(char c : words[idx]){
            curr[c-'a']--;
            if(curr[c-'a'] < 0) {
                return ans;
            }
            sum += sc[c-'a'];
        }
        ans = max(ans, dfs(curr, idx + 1, sum, words, sc));
        return ans;
    }
};