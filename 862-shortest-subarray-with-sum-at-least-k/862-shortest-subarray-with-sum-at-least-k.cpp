class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        vector<long long> sum(n+1);
        for(int i = 0; i < n; i++)
            sum[i+1] = sum[i] + nums[i]; 

        deque<int> q;
        for(int i = 0; i <= n; i++){
            while(q.size() && sum[i] - sum[q.front()] >= k){
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            //因为sum[i]小，所以sum[j] - sum[i] >= sum[j] - sump[q.back()]
            //长度 j - i < q.back() - j
            //因此q.back()可以去掉
            while(q.size() && sum[i] <= sum[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};