class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        int n = nums.size();
        multiset<long> st;
        for(int i = 0; i < n; i++){
            //把区间左边多余的数删去
            if(i > k) st.erase(st.lower_bound(1l*nums[i-k-1]));//如果写st.erase(1l*nums[i-k-1])会删掉所有这个值的数
            //找是否有[nums[i] - t, nums[i] + t]的数
            auto iter = st.lower_bound(1l*nums[i] - t);
            if(iter != st.end() && abs(*iter - 1l*nums[i]) <= t) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};