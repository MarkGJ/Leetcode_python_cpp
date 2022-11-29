
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
    void dfs_inorder(vector<int> &res, TreeNode* root);
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs_inorder(result, root);
        return result;
    }
};
void Solution::dfs_inorder(vector<int>& res, TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    dfs_inorder(res, root->left);
    res.push_back(root->val);
    dfs_inorder(res, root->right);
}

// 本题采用dfs
/*
step 1:
  终止条件 节点为nullptr
step 2：
  循环体为 左 -> 中 -> 右边
  在中 添加 节点值
*/
