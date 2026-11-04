class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> stck;
        int numIslands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    stck.push_back({i, j});
                    grid[i][j] = '0';
                    numIslands++;
                }

                while(!stck.empty()) {
                    pair<int, int> tmp = stck.back();
                    stck.pop_back();

                    if (tmp.first - 1 >= 0 
                        && grid[tmp.first - 1][tmp.second] == '1') {
                        stck.push_back({tmp.first - 1, tmp.second});
                        grid[tmp.first - 1][tmp.second] = '0';
                    }

                    if (tmp.first + 1 < grid.size()
                        && grid[tmp.first + 1][tmp.second] == '1') {
                        stck.push_back({tmp.first + 1, tmp.second});
                        grid[tmp.first + 1][tmp.second] = '0';
                    }

                    if (tmp.second - 1 >= 0 
                        && grid[tmp.first][tmp.second - 1] == '1') {
                        stck.push_back({tmp.first, tmp.second - 1});
                        grid[tmp.first][tmp.second - 1] = '0';
                    }

                    if (tmp.second + 1 < grid[tmp.first].size()
                        && grid[tmp.first][tmp.second + 1] == '1') {
                        stck.push_back({tmp.first, tmp.second + 1});
                        grid[tmp.first][tmp.second + 1] = '0';
                    }
                }
            }
        }

        return numIslands;
    }
};
