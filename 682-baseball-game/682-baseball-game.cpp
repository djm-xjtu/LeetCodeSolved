class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        // -1e5
        vector<int> res(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ops[i] == "D"){
                int j = i - 1;
                while(res[j] == -1e5) j--;
                res[i] = res[j] * 2;
            }
            else if(ops[i] == "C"){
                int j = i - 1;
                while(res[j] == -1e5) j--;
                res[j] = -1e5;
                res[i] = -1e5;
            }
            else if(ops[i] == "+"){
                int j = i - 1;
                while(j >= 0 && res[j] == -1e5) j--;
                int k = j - 1;
                while(res[k] == -1e5) k--;
                res[i] = res[j] + res[k];
            }
            else{
                res[i] = stoi(ops[i]);
            }
        }

        for(int i = n - 1; i >= 0; i--){
            while(i > 0 && res[i] == -1e5) i--;
            if(i == 0 && res[i] == -1e5) break;
            ans += res[i];
        }
        return ans;
    }
};