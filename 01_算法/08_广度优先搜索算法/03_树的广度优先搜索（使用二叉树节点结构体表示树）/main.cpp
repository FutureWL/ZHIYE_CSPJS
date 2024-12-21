#include <iostream>
#include <queue>

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 树的广度优先搜索函数
void bfs(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* currentNode = nodeQueue.front();
        nodeQueue.pop();
        std::cout << currentNode->val << " ";

        if (currentNode->left != NULL) {
            nodeQueue.push(currentNode->left);
        }

        if (currentNode->right != NULL) {
            nodeQueue.push(currentNode->right);
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "树的广度优先搜索结果：" << std::endl;
    bfs(root);
    std::cout << std::endl;

    return 0;
}