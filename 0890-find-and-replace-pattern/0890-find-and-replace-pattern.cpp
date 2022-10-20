class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto str : words){
            if(check(str, pattern)) ans.push_back(str);
        }
        return ans;
    }
    //模式串匹配通解
    bool check(string a, string b){
        for(int i = 0; i < b.size(); i++){
            if(a.find(a[i]) != b.find(b[i])) return false;
        }
        return true;
    }
};