class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> network;

        int edgeCount = 0;
        for(auto edge : edges){
            network[edge[0]].push_back(edge[1]);
            network[edge[1]].push_back(edge[0]);
            edgeCount += 1;
        }

        if(edgeCount != n-1){
            return false;
        }

        if(edgeCount == 0 && n == 1){
            return true;
        }

        // nodes go from 0 to n-1

        set<int> visited;
        // start with edge 0
        stack<pair<int,int>> edgeSearch; // <parent, current>
        edgeSearch.push({-1,0});
        


        while(!edgeSearch.empty()){
            pair<int,int> node = edgeSearch.top();
            edgeSearch.pop();

            // make sure node exists in network
            if(network.find(node.second) == network.end() || (node.first != node.second && visited.find(node.second) != visited.end())){
                return false;
            }

            if(visited.find(node.second) != visited.end()){
                continue;
            }

            visited.insert(node.second);

            for(auto edge : network[node.second]){
                if(edge != node.first){
                    edgeSearch.push({node.second, edge});
                }
            }
        }

        return visited.size() == n;

        // go to edge 0s neighbors

        // if neighbor is != parent and already in visited
        // return false/ invalid tree

        // return false

    }
};
