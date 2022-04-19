class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 30; i >= 0; i--){
            int ones = 0, zeros = 0;
            for(auto j : nums){
                int t = (j >> i) & 1;
                if(t) ones++;
                else zeros++;
            }
            res += ones * zeros;
        }
        return res;
    }
};