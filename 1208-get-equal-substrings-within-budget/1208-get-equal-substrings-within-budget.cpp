class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int res = 0;
        int cnt = 0;
        int cost = 0;
        vector<int> h;
        for(int l = 0, r = 0; r < n; r++){
            while(cost > maxCost){
                cost -= h[l];
                cnt--;
                l++;
            }
            int p = abs(s[r] - t[r]);
            h.push_back(p);
            cost += p;
            cnt++;
            if(cost <= maxCost) res = max(res, cnt);
        }
        return res;
    }
};