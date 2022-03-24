class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> cache;
        for(auto &str : strs){
            auto t = str;
            sort(t.begin(), t.end());
            cache[t].push_back(move(str)); //move移动构造函数，移动完成后意味着str被删除了，作用是加速
        }
        vector<vector<string>> ans;
        for(auto i = cache.begin(); i != cache.end(); i++){
            ans.push_back(move(i->second));
        }
        
        return ans;
    }
};