class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int maxArea = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    int area = dfs(i, j, grid, visited);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[r][c] = 1;
        int area = 1;
        for(int i = 0;i<4;i++){
            int nr =  r+ dr[i];
            int nc =  c+ dc[i];
            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               grid[nr][nc] == 1 &&
               visited[nr][nc] == 0) {
                area += dfs(nr, nc, grid, visited);
            }
        }
        return area;
    }
};