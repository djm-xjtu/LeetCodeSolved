class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream raw(str);
        vector<string> strs;
        string line;
        while (raw >> line) strs.push_back(line);
        if (pattern.size() != strs.size()) return false;
        unordered_map<char, string> PS;
        unordered_map<string, char> SP;
        for (int i = 0; i < pattern.size(); i ++ )
        {
            if (PS.count(pattern[i]) == 0) PS[pattern[i]] = strs[i];
            if (SP.count(strs[i]) == 0) SP[strs[i]] = pattern[i];
            if (PS[pattern[i]] != strs[i]) return false;
            if (SP[strs[i]] != pattern[i]) return false;
        }
        return true;
    }
};