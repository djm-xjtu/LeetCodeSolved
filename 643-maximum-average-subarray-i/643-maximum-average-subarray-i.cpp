class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -1e9, t = 0;
        for(int i = 0; i < k; i++) t += nums[i];
        for(int l = 0, r = k - 1; r < nums.size(); l++, r++){
            if(l > 0) t -= nums[l-1];
            if(r > k - 1) t += nums[r];
            res = max(res, t / k);
        }
        return res;
    }
};