class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long sum = accumulate(b.begin(), b.end(), 1ll*0);
        auto check = [&](long long t) {
            long long sumt = 0;
            for(int i : b) sumt += min(t, (long long)i);
            return sumt / t >= n;
        };
        long long l = 0, r = sum / n;
        while(l < r){
            long long mid = l + r + 1>> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};