class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int idx = 0;
        for(int i = 0; i < g.size(); i++){
            while(idx < s.size() && g[i] > s[idx]) idx++;
            if(idx < s.size() && g[i] <= s[idx]) res++, idx++;
        }
        return res;
    }
};