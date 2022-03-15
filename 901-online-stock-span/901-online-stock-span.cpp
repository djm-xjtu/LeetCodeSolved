class StockSpanner {
public:
    stack<int> prices;
    stack<int> days;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int day = 1;
        while(prices.size() && prices.top() <= price){
            day += days.top();
            days.pop();
            prices.pop();
        }
        prices.push(price);
        days.push(day);
        return day;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */