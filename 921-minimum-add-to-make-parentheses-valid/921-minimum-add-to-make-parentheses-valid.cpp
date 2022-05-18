class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans = 0;
        for(auto t : s){
            if(t == '('){
                cnt++;
            }
            else{
                cnt--;
                if(cnt < 0){
                    cnt++;
                    ans++;
                }
            }
        }
        ans += cnt;
        return ans;
    }
};