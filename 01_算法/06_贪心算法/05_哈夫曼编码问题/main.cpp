#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

// 哈夫曼树节点结构体
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char ch, int freq) : data(ch), frequency(freq), left(NULL), right(NULL) {}
};

// 比较函数，用于在优先队列中按照节点频率从小到大排序（构建最小堆）
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// 构建哈夫曼树的函数，体现贪心策略
HuffmanNode* buildHuffmanTree(unordered_map<char, int>& frequencyMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;
    // 将每个字符及其对应的频率节点加入最小堆
    for (auto& it : frequencyMap) {
        minHeap.push(new HuffmanNode(it.first, it.second));
    }
    while (minHeap.size() > 1) {
        // 取出频率最小的两个节点
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();
        // 创建一个新节点，频率为两个子节点频率之和，作为父节点
        HuffmanNode* parent = new HuffmanNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        // 将新的父节点加入最小堆
        minHeap.push(parent);
    }
    return minHeap.top();
}

// 递归生成哈夫曼编码的函数
void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == NULL) {
        return;
    }
    if (root->data != '\0') {
        huffmanCodes[root->data] = code;
    }
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// 主函数，展示哈夫曼编码生成过程
int main() {
    unordered_map<char, int> frequencyMap = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };
    HuffmanNode* root = buildHuffmanTree(frequencyMap);
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);
    for (auto& it : huffmanCodes) {
        cout << it.first << " : " << it.second << endl;
    }
    return 0;
}