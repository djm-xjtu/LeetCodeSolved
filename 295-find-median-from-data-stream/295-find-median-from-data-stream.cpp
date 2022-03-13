class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int> small;
    int len;
    MedianFinder() {
        len = 0;
    }
    
    void addNum(int num) {
        if(small.empty()) {
            small.push(num);
            len++;
            return;
        }
        if(small.top() >= num) small.push(num);
        else big.push(num);
        if(small.size() > big.size() + 1){
            int a = small.top();
            small.pop();
            big.push(a);
        }
        if(small.size() + 1 < big.size()){
            int b = big.top();
            big.pop();
            small.push(b);
        }
        len++;
    }
    
    double findMedian() {
        if(len%2){
            if(small.size()>big.size())return small.top();
            else return big.top();
        }
        else return ((long long)(small.top())+big.top())*0.5;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */