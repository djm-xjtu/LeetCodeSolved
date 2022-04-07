class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second >= b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        vector<pair<int, int>> t;
        vector<int> ans;
        for(auto i : nums){
            h[i]++;
        }
        for(auto i = h.begin(); i != h.end(); i++){
            t.push_back({i->first, i->second});
        }
        sort(t.begin(), t.end(), cmp);
        for(auto i = t.begin(); i != t.end(); i++){
            ans.push_back(i->first);
            --k;
            if(k == 0) break;
        }
        return ans;
    }
};