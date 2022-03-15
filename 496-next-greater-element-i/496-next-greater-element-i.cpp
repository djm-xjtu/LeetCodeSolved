class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int n = nums1.size(), m = nums2.size();
        vector<int> res(m,-1);
        vector<int> ans;
        int f[n];
        unordered_map<int, int> cache;
        for(int i = 0; i < n; i++){
            cache[nums1[i]] = i+1;
        }
        for(int i = 0; i < m; i++){
            if(cache[nums2[i]]) f[cache[nums2[i]]-1] = i;
        }
        for(int i = 0; i < m; i++){
            while(stk.size() && nums2[stk.top()] < nums2[i]){
                int cur = stk.top(); stk.pop();
                res[cur] = nums2[i];
            }
            stk.push(i);
        }
        for(int i = 0; i < n; i++){
            ans.push_back(res[f[i]]);
        }
        return ans;
    }
};