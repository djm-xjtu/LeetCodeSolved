class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans;
        int line = 1, cnt = 0;
        for(int i = 0; i < s.size(); i++){
            cnt += widths[s[i] - 'a'];
            if(cnt > 100) cnt = widths[s[i] - 'a'], line++;
        }
        ans.push_back(line);
        ans.push_back(cnt);
        return ans;
    }
};