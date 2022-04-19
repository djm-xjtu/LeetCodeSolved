class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int dp[100005];
        memset(dp, 0, sizeof dp);
        int start = 0;
        int end = 0;
        dp[0] = 1;
        for(int i = 0; i<s.size(); i++){
            if(!dp[i])continue;
            start = max(i+minJump,end+1);
            end = min((int)s.size()-1,i+maxJump);
            for(int j = start; j<=end; j++){
                if(s[j]=='0')dp[j] = 1;
            }
            if(dp[s.size()-1])return true;
        }
        return dp[s.size()-1];
    }
};