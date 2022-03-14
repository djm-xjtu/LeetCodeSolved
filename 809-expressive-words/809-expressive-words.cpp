class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for(int q = 0; q < words.size(); q++){
            if(check(s, words[q])) ans++;
        }
        return ans;
    }
    bool check(string a, string b){
        int i = a.length(), j = b.length();
        while(i >= 0 && j >= 0){
            if(a[i] != b[j]) return 0;
            int k = i, cnt1 = 0;
            while(i >= 0 && a[i] == a[k]) i--, cnt1++;
            int n = j, cnt2 = 0;
            while(j >= 0 && b[j] == b[n]) j--, cnt2++;
            if(cnt1 < cnt2) return 0;
            if(cnt1 == 2 && cnt2 == 1)  return 0;
        }
        return i == j;
    }
};