class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        set<int> visited;

        map<int,vector<int>> neighbors;
        int num = 0;
        for(int i = 0; i < edges.size(); i++){
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
            num += 1;
        }

        if(num != n-1){
            return false;
        }

        if(dfs(visited, neighbors, -1, 0)){
            return false;
        }

        return visited.size() == n;
    }

    bool dfs(set<int>& visited, map<int,vector<int>>& neighbors, int parent, int node){
        if(node != parent && visited.find(node) != visited.end()){
            return true;
        }

        visited.insert(node);

        bool notTree = false;
        for(auto neighbor : neighbors[node]){
            if(neighbor != parent){
                notTree |= (dfs(visited, neighbors, node, neighbor));
            }
        }

        return notTree;
    }
};
