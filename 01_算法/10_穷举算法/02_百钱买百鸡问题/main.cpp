#include <iostream>
using namespace std;

int main() {
    cout << "百钱买百鸡的可能方案如下：" << endl;
    for (int x = 0; x <= 20; x++) {  // 公鸡数量，最多20只（100钱全买公鸡最多20只）
        for (int y = 0; y <= 33; y++) {  // 母鸡数量，最多33只（100钱全买母鸡最多33只）
            int z = 100 - x - y;  // 小鸡数量，由总数100只减去公鸡和母鸡数量得到
            if (5 * x + 3 * y + z / 3 == 100 && z % 3 == 0) {
                cout << "公鸡：" << x << " 只，母鸡：" << y << " 只，小鸡：" << z << " 只" << endl;
            }
        }
    }
    return 0;
}