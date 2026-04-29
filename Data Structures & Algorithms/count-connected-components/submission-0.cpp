class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> graph;


        set<int> visited;

        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }


        int components = 0;

        for(int i = 0; i < n; i++){
            if(visited.find(i) == visited.end()){
                dfs(visited, graph, i);
                components += 1;
            }
        }

        // loop through each edge, perform dfs, each dfs = one component
        return components;
    }

    void dfs(set<int>& visited, map<int,vector<int>>& graph, int node){
        if(visited.find(node) != visited.end()){
            return;
        }// already looked at aka dont see parents

        visited.insert(node); // track visited

        for(auto neighbor : graph[node]){
            dfs(visited, graph, neighbor);
        } // go to components in connected components
    }
};
