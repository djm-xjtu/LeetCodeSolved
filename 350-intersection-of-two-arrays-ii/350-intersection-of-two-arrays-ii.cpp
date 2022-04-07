class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> h;
        vector<int> ans;
        for(auto i : nums1){
            h[i]++;
        }
        for(auto i : nums2){
            if(h[i] > 0) ans.push_back(i), h[i]--;
        }
        return ans;
    }
};