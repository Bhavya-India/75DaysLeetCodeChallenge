class Solution {
public:

    void dfs(vector<vector<int>>& image,
             int row,
             int col,
             int originalColor,
             int newColor) {

        // Boundary check
        if (row < 0 || col < 0 ||
            row >= image.size() ||
            col >= image[0].size()) {
            return;
        }

        // Stop if color doesn't match
        if (image[row][col] != originalColor) {
            return;
        }

        // Change color
        image[row][col] = newColor;

        // 4 directions
        dfs(image, row + 1, col, originalColor, newColor);
        dfs(image, row - 1, col, originalColor, newColor);
        dfs(image, row, col + 1, originalColor, newColor);
        dfs(image, row, col - 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color) {

        int originalColor = image[sr][sc];

        // If same color, no need to process
        if (originalColor == color) {
            return image;
        }

        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};