class Solution {
public:
    
    void dfs(vector<vector<int>>& heights,
             int row,
             int col,
             vector<vector<bool>>& visited) {

        visited[row][col] = true;

        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto &dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < heights.size() &&
                newCol >= 0 && newCol < heights[0].size() &&
                !visited[newRow][newCol] &&
                heights[newRow][newCol] >= heights[row][col]) {

                dfs(heights, newRow, newCol, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific borders
        for (int r = 0; r < m; r++) {
            dfs(heights, r, 0, pacific);
            dfs(heights, r, n - 1, atlantic);
        }

        // Atlantic borders
        for (int c = 0; c < n; c++) {
            dfs(heights, 0, c, pacific);
            dfs(heights, m - 1, c, atlantic);
        }

        vector<vector<int>> result;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};