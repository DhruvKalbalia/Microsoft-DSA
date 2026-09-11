class Solution {
public:
        int n, m;
    void dfs(vector<vector<int>>& grid, int i, int j, int time){
        if (i<0||i>=n||j<0||j>=m)
            return;

         // Empty cell
        if (grid[i][j] == 0)
            return;

        // Already rotten earlier
        if (grid[i][j] != 1 && grid[i][j] < time)
            return;

        grid[i][j] = time;

        dfs(grid, i+1, j, time+1);
        dfs(grid, i-1, j, time+1);
        dfs(grid, i, j+1, time+1);
        dfs(grid, i, j-1, time+1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==2){
                    dfs(grid,i,j,2);
                }
            }
        }

        int ans = 2;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==1)
                    return -1;

                ans = max(ans, grid[i][j]);
            }
        }

        return ans-2;
    }
};