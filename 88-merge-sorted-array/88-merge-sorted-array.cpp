class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < m; i++) q.push(nums1[i]);
        for(int i = 0; i < n; i++) q.push(nums2[i]);
        for(int i = 0; i < m + n; i++) nums1[i] = q.top(), q.pop();
    }
};