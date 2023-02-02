#include<iostream>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
class Solution {
    public:
    bool result = false;
    void pathSum(TreeNode* node, int target) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right && target == node->val) {
            result = true;
            return;
        }
        pathSum(node->left, target - node->val);
        pathSum(node->right, target - node->val);
    }
    bool haspathSum(TreeNode* root, int targetSum) {
        pathSum(root, targetSum);
        return result;
    }
};

class preOrder
{
private:
    /* data */
public:
    preOrder(/* args */);
    ~preOrder();
    void getValue(TreeNode* root) const {
        if (!root) {
            return;
        }
        getValue(root->left);
        std::cout << root->val << std::endl;
        getValue(root->right);
    }
};

preOrder::preOrder(/* args */)
{
}

preOrder::~preOrder()
{
}

int main() {
    std::cout << "start ..." << std::endl;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    preOrder p;
    p.getValue(root);
    std::cout << "valid done" << std::endl;
    Solution s;
    std::cout << s.haspathSum(root, 22) << std::endl;
}
