#include "headers.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }
};

TEST(Test, leetcode144) {
    Solution s;
    TreeNode root(1);
    TreeNode right1(2);
    root.right = &right1;

    TreeNode left1(3);
    right1.left = &left1;

    vector<int> res = s.preorderTraversal(&root);
    vector<int> rightAns {1, 2, 3};
    ASSERT_EQ(res, rightAns);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
