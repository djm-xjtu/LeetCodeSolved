class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        if(n < 2) return false;
        for(int i = 0; i < n - 1; i++) if(nums[i] == 0 && nums[i+1] == 0) return true;
        unordered_map<int, int> f;
        f[0] = -1;
        int i = 0;
        for(int st : nums){
            sum += st;
            //这个求mod和记录坐标保证子数组大小至少为2很帅
            int mod = sum % k;
            if((f.count(mod))){
                if(i - f[mod] > 1) return true;
            }
            else f[mod] = i;
            i++;
        }
        return false;
    }
};