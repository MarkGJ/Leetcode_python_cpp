
/*
这题的思路：
  采用dfs， 把问题简化为：
    1 根结点一下的左右子树是否镜像
      2 左右子树镜像，可以拆分为：
        a 左右子树的根节点情况，有灭有，灭有则为false， 有跳转到b
        b 根节点都有的情况下，判断节点值是否相同，以及左节点的左子树和右节点的右子树是否镜像，左节点的右子树和右节点的左子树是否镜像
*/


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
    bool isLeftRightMirror(TreeNode* left_tree, TreeNode* right_tree) {
        if (!left_tree && !right_tree) {
            return true;
        }
        if (!left_tree || !right_tree) {
            return false;
        }
        return (left_tree->val == right_tree->val) && isLeftRightMirror(left_tree->left, right_tree->right) && isLeftRightMirror(left_tree->right, right_tree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isLeftRightMirror(root->left, root->right);

    }
};

