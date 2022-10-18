class Solution {
public:
    int myAtoi(string s) {
        int sign = 0, n = s.size();
        long long ans = 0;
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i < n && s[i] == '-') sign = -1, i++;
        else if(i < n && s[i] == '+') sign = 1, i++;
        else sign = 1;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            ans *= 10;
            ans += s[i] - '0';
            if(ans * sign > INT_MAX) return INT_MAX;
            if(ans * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return ans * sign;
    }
};