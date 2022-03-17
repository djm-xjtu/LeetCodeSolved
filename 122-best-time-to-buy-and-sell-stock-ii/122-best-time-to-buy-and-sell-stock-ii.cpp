class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min_val = 1e5;
        for(int i : prices){
            if(i < min_val) min_val =  i;
            else{
                profit += i - min_val;
                min_val = i;
            }
        }
        return profit;
    }
};