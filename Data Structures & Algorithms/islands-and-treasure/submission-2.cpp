class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != 2147483647){
                    continue;
                }

                grid[nx][ny] = 1+grid[x][y];
                q.push({nx,ny});
            }
        }
    }
};
