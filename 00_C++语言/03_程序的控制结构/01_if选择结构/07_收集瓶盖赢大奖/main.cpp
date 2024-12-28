#include <iostream>
#include <unordered_map>

int main() {
    // ���ڼ�¼ÿ��ƿ�ǵ�����
    std::unordered_map<char, int> capCount;
    char cap;

    std::cout << "�������ռ�����ƿ�ǣ����������ĸ���������룩��" << std::endl;
    while (std::cin >> cap && std::isalpha(cap)) {
        if (capCount.find(cap) != capCount.end()) {
            capCount[cap]++;
        }
        else {
            capCount[cap] = 1;
        }
    }

    // �����ռ���3��'A'ƿ�Ǻ�5��'B'ƿ�ǿ���Ӯ��
    if (capCount.find('A') != capCount.end() && capCount['A'] >= 3 &&
        capCount.find('B') != capCount.end() && capCount['B'] >= 5) {
        std::cout << "��ϲ�㣬Ӯ�ô󽱣�" << std::endl;
    }
    else {
        std::cout << "���ź���δ�ﵽӮ��������" << std::endl;
    }

    return 0;
}