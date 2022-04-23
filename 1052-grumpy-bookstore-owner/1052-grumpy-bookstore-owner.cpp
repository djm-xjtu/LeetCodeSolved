class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int cnt = 0;
        int res = 0;
        int good = 0;
        for(int l = 0, r = 0; r < n; r++){
            while(r - l + 1 > minutes){
                if(grumpy[l] == 1) cnt -= customers[l];
                l++;
            }
            if(grumpy[r] == 1) cnt += customers[r];
            if(grumpy[r] == 0) good += customers[r];
            res = max(res, cnt);
        }
        return good + res;
    }
};