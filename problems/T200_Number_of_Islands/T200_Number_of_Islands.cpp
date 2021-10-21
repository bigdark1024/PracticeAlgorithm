#include "headers.h"

class Solution {
 private:
  int row;
  int col;
  const char LAND = '1';
  const char VISTED = '2';
 public:
  int numIslands(vector<vector<char>> &grid) {
    row = grid.size();
    col = grid[0].size();

    int count = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == LAND) {
          count++;
          dfs(grid, i, j);
        }
      }
    }

    return count;
  }

  void dfs(vector<vector<char>> &grid, int r, int c) {
    if (!(r >= 0 && r < row && c >= 0 && c < col)) {
      return;
    }

    if (grid[r][c] != LAND) {
      return;
    }

    grid[r][c] = VISTED;

    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
  }
};

TEST(T200_Number_of_Islands, testcase1) {
  Solution s;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
