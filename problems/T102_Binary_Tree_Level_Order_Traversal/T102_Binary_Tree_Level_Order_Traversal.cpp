#include "headers.h"

// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
// 示例：
// 二叉树：[3,9,20,null,null,15,7],
// 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
class Solution 
{
 private:
    vector<vector<int>> ret; 
 public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == NULL) {
            return ret;
        }

        queue<TreeNode*> que;
        que.push(root);
        while (que.size() > 0) {
            int n = que.size();
            vector<int> tmp;
            while (n > 0) {
                auto curr = que.front();
                que.pop();
                tmp.push_back(curr->val);

                if (curr->left != NULL) {
                    que.push(curr->left);
                }

                if (curr->right != NULL) {
                    que.push(curr->right);
                }
                n--;
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};

TEST(T102_Binary_Tree_Level_Order_Traversal, T102_Binary_Tree_Level_Order_Traversal) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
