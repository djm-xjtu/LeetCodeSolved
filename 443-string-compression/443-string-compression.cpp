class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1) return 1;
        vector<char> s;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(i > 0 && chars[i-1] != chars[i]){
                s.push_back(chars[i-1]);
            }
            else if(i > 0 && chars[i-1] == chars[i]){
                int t = 1;
                while(i < n && chars[i-1] == chars[i]){
                    t++;
                    i++;
                }
                s.push_back(chars[i-1]);
                string p = to_string(t);
                for(int j = 0; j < p.size(); j++) s.push_back(p[j]);
            }
        }
        if(chars[n-1] != chars[n-2]) s.push_back(chars[n-1]);
        chars = s;
        return s.size();
    }
};