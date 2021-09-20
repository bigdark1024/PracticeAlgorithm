#include "headers.h"

/**
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * */
class Solution {
 public:
  int minDepth(TreeNode *root) {
    int res = 0;
    if (root == nullptr) {
      return res;
    }

    queue<TreeNode *> que;
    que.push(root);
    int step = 0;

    while (que.size() > 0) {
      int size = que.size();
      step++;
      for (int i = 0; i < size; ++i) {
        TreeNode *curr = que.front();
        que.pop();

        if (curr->right != nullptr) {
          que.push(curr->right);
        }

        if (curr->left != nullptr) {
          que.push(curr->left);
        }

        if (curr->left == nullptr && curr->right == nullptr) {
          return step;
        }
      }
    }

    return res;
  }
};

TEST(T111_Minimum_Depth_of_Binary_Tree, testcase1) {
  Solution s;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
