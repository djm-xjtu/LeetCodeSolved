class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> h;
        vector<string> ans;
        if(s.size() < 10) return ans;
        for(int i = 0; i <= s.size() - 10; i++){
            string t = "";
            for(int j = i; j <= i + 9; j++){
                t += s[j];
            }
            h[t]++;
            if(h[t] == 2) ans.push_back(t);
        }
        return ans;
    }
};