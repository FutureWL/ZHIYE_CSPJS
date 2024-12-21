#include <iostream>

// 二叉树节点结构体定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归计算二叉树高度的函数
int getTreeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int main() {
    // 构建一个简单的二叉树示例
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = getTreeHeight(root);
    std::cout << "该二叉树的高度为: " << height << std::endl;
    return 0;
}