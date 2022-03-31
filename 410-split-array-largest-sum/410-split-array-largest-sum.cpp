class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long l = nums[0], r = 0;
        for(auto i : nums){
            l = l > i ? l : i;
            r += i;
        }
        while(l < r){
            long mid = l + r >> 1;
            long tmp = 0;
            int cnt = 1;
            for(auto i : nums){
                tmp += i;
                if(tmp > mid){
                    ++cnt;
                    tmp = i;
                }
            }
            
            if(cnt <= m) r = mid;
            else l = mid + 1;
        }
        
        return l;
    }
};