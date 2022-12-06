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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        return (q->val == p->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 

    }
};


/*
本题的思路是：
  两个树相同拆分起来就是每个节点都相同，那么考虑节点的情况分为：
    1 两个节点都为空
    2 两个节点有一个不为空
    3 两个节点都不为空，那么当前节点值是否相同以及当前节点的左子树和右子树是否相同
*/
