class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, ans = 0;
        for(auto t : s){
            if(t == '[') cnt++;
            else{
                cnt--;
                if(cnt < 0){
                    cnt += 2;
                    ans++;
                }
            }
        }
        return ans;
    }
};