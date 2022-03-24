class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            int j = i;
            while(j < n && s[j] != ' ') j++;
            string t = s.substr(i, j - i) + " ";
            ans.insert(0, t);
            i = j;
        }
        auto itr = ans.begin();
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] != ' ') break;
            ans.erase(itr);
            itr++;
        }
        ans.pop_back();
        return ans;
    }
};