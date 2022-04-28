class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        int sum = 0;
        int idx = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            if(sum < 0){
                sum = 0;
                idx = i + 1;
            }
        }
        return idx;
    }
};