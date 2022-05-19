class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long num = 0, lo = 0, hi = 0;
        for(auto st : differences){
            num += st;
            lo = min(num, lo);
            hi = max(num, hi);
        }
        int ans = (upper + lo) - (lower + hi) + 1;
        // xn = xo + (diff[0] + ... + diff[n-1])
        // xn - (...) >= lower => xn >= lower + (...) ->max 恒成立
        // xn - (...) <= higher => xn <= higher + (...) ->min 恒成立
        if(ans > 0) return ans;
        return 0;
    }
};