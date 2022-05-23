typedef pair<int, string> PIS;
class SORTracker {
public: 
    int cnt;
    //override priority_queue is quite opposite to vector
    struct cmp1 { 
        bool operator ()(PIS &a,PIS &b) { 
            if(a.first != b.first)
                return a.first < b.first; //表示小的优先
            return a.second > b.second; //表示大的优先
        } 
    };
    struct cmp2 { 
        bool operator ()(PIS &a,PIS &b) { 
            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        } 
    };
    priority_queue<PIS, vector<PIS>, cmp1> q1; // da
    priority_queue<PIS, vector<PIS>, cmp2> q2; // xiao
    SORTracker() {
        cnt = 1;
    }
    
    void add(string name, int score) {
        PIS t = {score, name};
        q1.push(t);
        q2.push(q1.top());
        q1.pop();
    }
    
    string get() {
        while(q2.size() < cnt){
            q2.push(q1.top());
            q1.pop();
        }
        while(q2.size() > cnt){
            q1.push(q2.top());
            q2.pop();
        }
        cnt++;
        return q2.top().second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */