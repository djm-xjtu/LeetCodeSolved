class Solution {
public:
    int find(vector<int>& parent, int index){
        if(parent[index] != index) parent[index] = find(parent, parent[index]);
        return parent[index];
    }
    void Union(vector<int>& parent, int index1, int index2){
        parent[find(parent, index1)] = find(parent, index2);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(auto& edge : edges){
            int a = edge[0], b = edge[1];
            if(find(parent, a) != find(parent, b)) Union(parent, a, b);
            else return edge;
        }
        return {};
    }
};
