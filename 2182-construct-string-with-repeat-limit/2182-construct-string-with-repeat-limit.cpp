class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        unordered_map<char, int> h;
        for(int i = 0; i < s.size(); i++){
            h[s[i]]++;
        }
        int count = 0;
        string res = "";
        while(count < s.size()){
            int cnt = 0;
            char chose;
            bool f = 0, vis = 0;
            for(char st = 'z'; st >= 'a'; st--){
                if(h[st] > 0){
                    chose = st;
                    if(h[st] >= limit) cnt = limit, h[st] -= limit, count += limit;
                    else cnt = h[st], h[st] = 0, count += h[st];
                    if(h[st] == 0) f = 1;
                    for(int i = 0; i < cnt; i++) res += st;
                    break;
                }
            }
            if(f) continue;
            for(char st = chose - 1; st >= 'a'; st--){
                if(h[st]){
                    vis = 1;
                    h[st]--, count++;
                    res += st;
                    break;
                }
            }
            if(!vis) break;
        }
        return res;
    }
};