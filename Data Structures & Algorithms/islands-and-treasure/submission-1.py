class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        # bfs the graph
        # find all treasures
        # perform bfs finding the minimum distance between current and new


        currentLand = set()

        def bfs(r, c, newVal):

            if r < 0 or c < 0 or r > len(grid)-1 or c > len(grid[0])-1 or grid[r][c] == -1 or (r,c) in currentLand or grid[r][c] < newVal:
                return
            grid[r][c] = newVal
            currentLand.add((r,c))
            bfs(r+1,c,grid[r][c]+1)
            bfs(r-1,c,grid[r][c]+1)
            bfs(r,c+1,grid[r][c]+1)
            bfs(r,c-1,grid[r][c]+1)
            currentLand.remove((r,c))
        
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 0:
                    bfs(r, c, 0)