class MovingAverage {
public:
    int size;
    int cnt = 0;
    vector<int> a;
    double sum = 0;
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if(cnt < size){
            cnt++;
            a.push_back(val);
            sum += val;
            return sum / cnt;
        }
        sum -= a[0];
        sum += val;
        a.erase(a.begin());
        a.push_back(val);
        return sum / size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */