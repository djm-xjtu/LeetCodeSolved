/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs1(TreeNode* root, vector<string>& t){
        if(!root) return;
        t.push_back(to_string(root->val));
        dfs1(root->left, t);
        dfs1(root->right, t);
    }
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        vector<string> t;
        dfs1(root, t);
        string str = "";
        for(int i = 0; i < t.size(); i++){
            str += t[i];
            if(i != t.size() - 1) str += ","; 
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* dfs2(vector<int>& s, int l, int r){
        if(l > r) return nullptr;
        int j = l + 1, t = s[l];
        while(j <= r && s[j] <= t) j++;
        TreeNode* res = new TreeNode(t);
        res->left = dfs2(s, l + 1, j - 1);
        res->right = dfs2(s, j, r);
        return res;
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        vector<int> s;
        for(int i = 0; i < data.size(); i++){
            if(data[i] != ','){
                int j = i;
                while(j < data.size() && data[j] != ',') j++;
                s.push_back(stoi(data.substr(i, j - i)));
                i = j;
            }
        }
        return dfs2(s, 0, s.size() - 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;