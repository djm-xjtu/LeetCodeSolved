class Solution {
public:
    int uniqueLetterString(string s) {
        long long ans = 0;
        int n = s.size();
        int mod = 1e9 + 7;
        vector<int> right(n, -1);
        vector<int> left(n, -1);
        vector<int> prev(26, -1);
        vector<int> ne(26, n);
        for(int i = 0; i < n; i++){
            left[i] = prev[s[i] - 'A'];
            prev[s[i] - 'A'] = i;
        }
        for(int i = n-1; i >= 0; i--){
            right[i] = ne[s[i] - 'A'];
            ne[s[i] - 'A'] = i;
        }
        for(int i = 0; i < n; i++){
            ans = (ans + (i - left[i]) * (right[i] - i)) % mod;
        }
        return ans;
    }
};