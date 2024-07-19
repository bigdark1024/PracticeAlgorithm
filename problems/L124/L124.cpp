#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode) {};
};

/**
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 *
 * 124. 二叉树中的最大路径和
 * */
class Solution {
public:
    int res = 0;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftMax = std::max(0, maxPathSum(root->left));
        int rightMax = std::max(0, maxPathSum(root->right));
        res = std::max(res , leftMax + rightMax + root->val);
        return leftMax + rightMax + root->val;
    }
};

int main(int argc, char **argv) {
    TreeNode leftNode = TreeNode(2);
    TreeNode rightNode = TreeNode(3);

    TreeNode *root = {};
    root = (TreeNode*) malloc(sizeof(struct TreeNode));
    if (root == nullptr) {
        return -1;
    }
    root->val = 1;
    root->left = &leftNode;
    root->right = &rightNode;

    Solution s;
    int maxSum = s.maxPathSum(root);
    std::cout << maxSum << std::endl;
}
