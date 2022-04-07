class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> h;
        int res = 0;
        for(auto i : nums1){
            for(auto j : nums2){
                h[i + j]++;
            }
        }
        for(auto i : nums3){
            for(auto j : nums4){
                if(h[-(i + j)]) res += h[-(i + j)];
            }
        }
        return res;
    }
};