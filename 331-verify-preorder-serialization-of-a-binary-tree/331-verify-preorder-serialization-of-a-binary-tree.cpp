class Solution {
public:
    bool ans = 1;
    bool isValidSerialization(string preorder) {
        preorder += ',';
        int idx = 0;
        dfs(preorder, idx);
        cout << ans << " " << idx;
        cout << preorder.size();
        return ans && idx == preorder.size(); // cycle ends but idx != size 多节点
    }
    void dfs(string& pre, int& index){
        if(index == pre.size()){
            ans = 0;//cycle not end but index is end 少节点
            return;
        }
        if(pre[index] == '#'){
            index+=2;
            return;
        }
        while(pre[index] != ',') index++; index++;
        dfs(pre, index);
        dfs(pre, index);
    }
};