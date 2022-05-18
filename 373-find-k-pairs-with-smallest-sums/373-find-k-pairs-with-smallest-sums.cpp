class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        //a[0] + b[0], a[0] + b[1] ... a[0] + b[m-1]
        //a[1] + b[0], a[1] + b[1] ... a[1] + b[m-1]
        //...
        //a[n-1] + b[0], a[n-1] + b[1] ... a[n-1] + b[m-1]
        // ascending arrays
        for(int i = 0; i < n; i++){
            q.push({nums1[i] + nums2[0], i, 0}); // push head of each ascending arrays into heap
        }
        while(k-- && q.size()){
            auto t = q.top(); q.pop();
            ans.push_back({nums1[t[1]], nums2[t[2]]});
            if(t[2] + 1 < m) q.push({nums1[t[1]] + nums2[t[2] + 1], t[1], t[2] + 1});
        }
        return ans;
    }
};