class Solution {
public:
    class Node{
        public:
        int level, visited;
        vector<Node*> ne;
        Node(){
            level = 0, visited = 0;
        }
    };
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        Node* res[n + 1];
        for(int i = 1; i <= n; i++){
            Node* t = new Node();
            res[i] = t;
        }
        for(int i = 0; i < edges.size(); i++){
            res[edges[i][0]]->ne.push_back(res[edges[i][1]]);
            res[edges[i][1]]->ne.push_back(res[edges[i][0]]);
        }
        queue<Node*> q;
        q.push(res[1]);
        res[1]->visited++;
        
        int ans = 0, level = 0;
        while(q.size()){
            int len = q.size();
            level++;
            if((ans / change) % 2) ans = (ans / change + 1) * change;
            ans += time;
            while(len--){
                auto t = q.front(); q.pop();
                for(auto node : t->ne){
                    if(node == res[n] && node->level != 0 && node->level != level) return ans;
                    if(node->level != level && node->visited < 2){
                        q.push(node);
                        node->level = level;
                        node->visited++;
                    }
                }
            }
        }
        return -1;
    }
};