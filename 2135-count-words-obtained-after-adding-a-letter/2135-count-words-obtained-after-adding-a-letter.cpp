class Solution {
public:
    int wordCount(vector<string>& st, vector<string>& ed) {
        //如果字母只出现一次，可以用位运算表示
        unordered_set<int> h;
        int cnt = 0;
        for(auto t : st){
            int mask = 0;
            for(char s : t){
                mask |= (1 << (s - 'a'));
            }
            h.insert(mask);
        }
        for(auto t : ed){
            int mask = 0;
            for(char s : t){
                mask |= (1 << (s - 'a'));
            }
            for(char s : t){
                if(h.count(mask ^ (1 << (s - 'a')))){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};