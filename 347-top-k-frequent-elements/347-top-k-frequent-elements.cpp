class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        vector<int> ans;
        for(auto i : nums){
            h[i]++;
        }
        int cnt = 0;
        for(auto i : h){ //&
            if(cnt < k){
                ++cnt;
                q.push({i.second, i.first});
            }
            else{
                if(q.top().first < i.second){
                    q.pop();
                    q.push({i.second, i.first});
                }
            }
        }
        for(int i = 0; i < k; i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};