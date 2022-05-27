class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefix(n+1, 0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + (hours[i-1]>8 ? 1 : -1);
        }
        stack<int> s;
        //把前缀和小于0的放入栈中
        for(int i=0;i<=n;i++){
            if(s.empty() || prefix[s.top()] > prefix[i]){
                s.push(i);
            }
        }
        int ans = 0;
        //找到最远的符合条件的i
        for(int i=n;i>=0;i--){
            while(!s.empty() && prefix[i] > prefix[s.top()]){
                ans = fmax(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};