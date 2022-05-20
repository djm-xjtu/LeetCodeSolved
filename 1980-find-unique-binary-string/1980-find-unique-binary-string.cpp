class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> res;
        int n = nums.size();
        for(auto st : nums){
            int t = 0;
            for(int i = 0; i < n; i++){
                t *= 2;
                t += st[i] - '0';
            }
            res.insert(t);
        }

        for(int i = 0; i < 20; i++){
            if(!res.count(i)) {
                string s = "";
                for(int j = n - 1; j >= 0; j--){
                    if(i - pow(2, j) >= 0){
                        i -= pow(2, j);
                        s += "1";
                    }
                    else s += "0";
                }
                return s;
            }
        }
        return "";
    }
};