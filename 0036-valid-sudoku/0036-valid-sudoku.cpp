class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char val = board[i][j];

                if (val == '.') continue;

                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check duplicates
                if (rows[i].count(val) ||
                    cols[j].count(val) ||
                    boxes[boxIndex].count(val)) {
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                boxes[boxIndex].insert(val);
            }
        }

        return true;
    }
};