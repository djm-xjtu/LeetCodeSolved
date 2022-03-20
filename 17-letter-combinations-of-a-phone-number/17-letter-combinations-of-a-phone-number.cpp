class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        string cache[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        vector<string> res;
        res.push_back("");
        for(int i = 0; i < n; i++){
            int t = digits[i] - '0';
            string s = cache[t];
            int len1 = res.size();
            int len2 = s.size();
            vector<string> newres;
            for(int j = 0; j < len1; j++){
                for(int k = 0; k < len2; k++){
                    newres.push_back(res[j] + s[k]);
                }
            }
            res = newres;
        }
        return res;
    }
};