class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> res;
        int l = 0, r = n;
        for(int i = 0; i < n; i++){
            if(s[i] == 'I') res.push_back(l++);
            else res.push_back(r--);
        }
        res.push_back(l);
        return res;
    }
};