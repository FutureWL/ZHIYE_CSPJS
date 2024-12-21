#include <iostream>

// 二叉树节点结构体定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 先序遍历二叉树的递归函数
void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // 构建一个简单的二叉树示例
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "先序遍历结果: ";
    preorderTraversal(root);
    std::cout << std::endl;

    return 0;
}