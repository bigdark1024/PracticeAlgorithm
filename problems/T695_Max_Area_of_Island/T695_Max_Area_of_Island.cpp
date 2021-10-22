#include "headers.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visted(row, vector<bool>(col, false));
        int max = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int count = 0;
                if (grid[i][j] == LAND) {
                    count = dfs(grid, visted, i, j);
                    max = std::max(max, count);
                }
            }
        }

        return max;
    }

    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visted, int r, int c) {
        if (r < 0 || r >= row || c < 0 || c >= col) {
            return 0;
        }

        if (grid[r][c] != LAND) {
            return 0;
        }

        grid[r][c] = VISTED;
        int tmpCounter = 1;
        tmpCounter += dfs(grid, visted, r + 1, c);
        tmpCounter += dfs(grid, visted, r - 1, c);
        tmpCounter += dfs(grid, visted, r, c + 1);
        tmpCounter += dfs(grid, visted, r, c - 1);
        return tmpCounter;
    }

private:
    int row;
    int col;
    const int LAND = 1;
    const int VISTED = 2;
};

TEST(T695_Max_Area_of_Island, testcase1) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
