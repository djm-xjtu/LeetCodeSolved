class Solution {
public:
    int balancedString(string s) {
        //只需要判断多出来的，会自动填补少了的！
        //Two Point:滑动串口类型
        int cnt[4], n = s.size();
        int ans = n;
        memset(cnt, 0, sizeof cnt);
        unordered_map<char, int> h;
        h['Q'] = 0, h['W'] = 1, h['E'] = 2, h['R'] = 3;
        for(char str : s)
            cnt[h[str]]++;
        for(int i = 0; i < 4; i++)
            cnt[i] -= n / 4;
        int l = 0, r = 0;
        int cur[4];
        memset(cur, 0 ,sizeof cur);
        while(r < n){
            int idxr = h[s[r]];
            cur[idxr]++;
            while(check(cur, cnt)){
                ans = min(ans, r - l + 1);
                int idxl = h[s[l]];
                cur[idxl]--;
                l++;
            }
            r++;
        }
        return ans;
    }
    //判断可以cur完全覆盖多出来的字符
    bool check(int* cur, int* cnt){
        for(int i = 0; i < 4; i++){
            if(cur[i] < cnt[i]) return false;
        }
        return true;
    }
};