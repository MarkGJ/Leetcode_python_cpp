
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
    vector<TreeNode*> generate(int start, int end);
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return {};
        }
        return generate(1, n);


    }
};
vector<TreeNode*> Solution::generate(int start, int end)
{
    if (start > end) {
        return {nullptr};
    }
    vector<TreeNode*> allTree;
    // 根节点
    for (int i(start); i <= end; i++) {
        vector<TreeNode*> l_all = generate(start, i -1);
        vector<TreeNode*> r_all = generate(i+1, end);
        for (auto l : l_all) {
            for (auto r : r_all) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                allTree.push_back(root);
            }
        }
    }
    return allTree;
}

/* 
思路：
  第一步： 1-n， 遍历每一值k， k的左边是左子树， k的右边是右子树
  第二步： 每一个根节点，都可以跟左子树和右子树的所有可能。
  第三步：递归返回。
  
  */
