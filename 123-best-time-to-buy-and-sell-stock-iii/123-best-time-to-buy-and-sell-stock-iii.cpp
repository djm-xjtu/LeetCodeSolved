class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = prices[0], buy2 = prices[0];
        int sell1 = 0, sell2 = 0;
        for(int price : prices){
            buy1 = min(buy1, price); //buy stock1
            sell1 = max(sell1, price - buy1);//sell stock1
            buy2 = min(buy2, price - sell1);//buy stock2
            sell2 = max(sell2, price - buy2);//sell stock2
        }
        return sell2;
    }
};