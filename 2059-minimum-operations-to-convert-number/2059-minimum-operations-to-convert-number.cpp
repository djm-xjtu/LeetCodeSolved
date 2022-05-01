class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        q.push(start);
        int step = 0;
        int vis[1010];
        for(int i = 0; i < 1010; i++) vis[i] = 0;
        vis[start] = 1;
        while(q.size()){
            int len = q.size();
            step++;
            while(len--){
                auto t = q.front(); q.pop();
                for(auto num : nums){
                    int a = t + num, b = t - num, c = t ^ num;
                    if(a == goal || b == goal || c == goal) return step;
                    if(!(a < 0 || a > 1000 || vis[a] == 1)) q.push(a), vis[a] = 1;
                    if(!(b < 0 || b > 1000 || vis[b] == 1)) q.push(b), vis[b] = 1;
                    if(!(c < 0 || c > 1000 || vis[c] == 1)) q.push(c), vis[c] = 1;
                }
            }
        }
        return -1;
    }
};