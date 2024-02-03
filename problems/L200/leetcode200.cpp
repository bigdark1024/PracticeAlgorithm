#include "headers.h"

class Solution {
public:
    int ret = 0;
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return ret;
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>> &grid, int x, int y) {
        if (!(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())) {
            // 说明左边越界
            return;
        }

        if (grid[x][y] == '0') { // 如果是水则返回， 只遍历陆地
            return;
        }
        if (grid[x][y] == '2') { // 说明已经遍历过了
            return;
        }
        grid[x][y] = '2'; // 标记已经访问过的陆地为

        dfs(grid, x - 1, y); // 上
        dfs(grid, x + 1, y); // 下
        dfs(grid, x, y - 1); // 左
        dfs(grid, x, y + 1); // 右
    }
};

TEST(Test, solution) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
