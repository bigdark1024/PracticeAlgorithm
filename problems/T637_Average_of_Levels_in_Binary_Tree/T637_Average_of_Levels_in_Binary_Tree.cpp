#include "headers.h"

class Solution {
 private:
  vector<double> res;
 public:
  vector<double> averageOfLevels(TreeNode *root) {
    if (root == NULL) {
      return res;
    }

    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int levelSize = que.size();
      double levelSum = 0.0;
      for (int i = 0; i < levelSize; ++i) {
        auto curr = que.front();
        que.pop();
        levelSum += curr->val;

        if (curr->left != nullptr) {
          que.push(curr->left);
        }

        if (curr->right != nullptr) {
          que.push(curr->right);
        }
      }
      res.push_back(levelSum / levelSize);
    }
    return res;
  }
};

TEST(T637_average_of_levels_in_btree, testcase1) {
  Solution s;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
