class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for(int i = 0; i <= k; i++){
            cardPoints.push_back(cardPoints[i]);
        }
        int res = 0;
        int cnt = 0;
        for(int i = n - k, j = n - k; j < n; i++){
            while(i - j + 1 > k){
                cnt -= cardPoints[j];
                j++;
            }
            cnt += cardPoints[i];
            res = max(res, cnt);
        }
        return res;
    }
};