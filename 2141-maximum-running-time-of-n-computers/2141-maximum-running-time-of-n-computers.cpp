class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        using ll = long long;
        ll sum = accumulate(b.begin(), b.end(), 1ll*0);
        auto check = [&](ll t){
            ll sumt = 0;
            for(int i : b) sumt += min(t, 1ll*i);
            return sumt >= t * n;
        };
        ll l = 0, r = sum / n;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};