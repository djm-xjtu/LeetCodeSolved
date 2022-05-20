class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> h;
        int i = 0;
        for(auto st : intervals){
            h[st[0]] = i;
            i++;
        }
        vector<int> ans;
        for(auto st : intervals){
            auto x = h.lower_bound(st[1]);
            if(x == h.end()) ans.push_back(-1);
            else ans.push_back((*x).second);
        }
        return ans;
    }
};