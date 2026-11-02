class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<std::unordered_set<char>> rowSets(9);
        vector<std::unordered_set<char>> colSets(9);
        vector<std::unordered_set<char>> boxSets(9);
        
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char cur = board[row][col];
                if (cur == '.') continue;

                bool foundInRow = rowSets[row].contains(cur);
                bool foundInCol = colSets[col].contains(cur);

                int boxCol = col == 0 ? 0 : col / 3;
                int boxRow = row == 0 ? 0 : row / 3;
                int coordToBox = (boxRow * 3) + boxCol;

                bool foundInBox = boxSets[coordToBox].contains(cur);

                if (foundInRow || foundInCol || foundInBox) return false;

                rowSets[row].insert(cur);
                colSets[col].insert(cur);
                boxSets[coordToBox].insert(cur);
            }
        }

        return true;
    }
};
