class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int n = nums1.size(), m = nums2.size();
        vector<int> res(m,-1);
        vector<int> ans;
        unordered_map<int, int> cache;
        for(int i = 0; i < m; i++){
            while(stk.size() && nums2[stk.top()] < nums2[i]){
                int cur = stk.top(); stk.pop();
                cache[nums2[cur]] = nums2[i]+1;
            }
            stk.push(i);
        }
        for(int i = 0; i < n; i++){
            if(cache[nums1[i]] != 0) ans.push_back(cache[nums1[i]]-1);
            else ans.push_back(-1);
        }
        return ans;
    }
};