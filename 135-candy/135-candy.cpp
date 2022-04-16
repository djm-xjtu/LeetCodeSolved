class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> sweet(n, 1);
        sweet[0] = 1;
        for(int i = 0; i < n - 1; i++){
            if(ratings[i] < ratings[i+1]){
                sweet[i+1] = sweet[i] + 1;
            }
        }
        for(int i = n - 1; i > 0; i--){
            if(ratings[i-1] > ratings[i]){
                sweet[i-1] = max(sweet[i] + 1, sweet[i-1]);
            }
        }
        long ans = 0;
        for(int i = 0; i < n; i++) ans += sweet[i];
        return ans;
    }
};