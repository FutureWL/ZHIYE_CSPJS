1. **�������**��
   - ��֮ǰ���ƣ��ӵص�A���ص�B����֪��·�ٶ� `v1`���ﳵ�ٶ� `v2` ��·�� `s`��������·���ﳵ����ʱ�䣬Ȼ��Ƚ����ߴ�С���� `switch` �����ݱȽϽ�������ͬ��Ϣ��
2. **����ʵ��**��
```cpp
#include <iostream>

int main() {
    double v1, v2, s;
    std::cout << "��������·�ٶ� v1(��λ: m/s): ";
    std::cin >> v1;
    std::cout << "�������ﳵ�ٶ� v2(��λ: m/s): ";
    std::cin >> v2;
    std::cout << "������·�� s(��λ: m): ";
    std::cin >> s;

    if (v1 <= 0 || v2 <= 0 || s <= 0) {
        std::cout << "������ٶȻ�·�̲���Ϊ�������㡣" << std::endl;
        return 1;
    }

    double walkTime = s / v1;
    double bikeTime = s / v2;

    int comparisonResult;
    if (walkTime < bikeTime) {
        comparisonResult = 1;
    } else if (walkTime > bikeTime) {
        comparisonResult = 2;
    } else {
        comparisonResult = 3;
    }

    std::cout << "��·��Ҫ��ʱ��Ϊ: " << walkTime << " ��" << std::endl;
    std::cout << "�ﳵ��Ҫ��ʱ��Ϊ: " << bikeTime << " ��" << std::endl;

    switch (comparisonResult) {
    case 1:
        std::cout << "��·��ʱ���̡�" << std::endl;
        break;
    case 2:
        std::cout << "�ﳵ��ʱ���̡�" << std::endl;
        break;
    case 3:
        std::cout << "��·���ﳵ��ʱ��ͬ��" << std::endl;
        break;
    default:
        break;
    }

    return 0;
}
```
3. **����˵��**��
   - **��������������**������ `v1`��`v2`��`s` �ֱ��ʾ��·�ٶȡ��ﳵ�ٶȺ�·�̣������û���ȡ��Щֵ��ͬʱ����������֤�����ٶȻ�·��Ϊ�������򱨴���������
   - **ʱ�����**�����ݹ�ʽ������·ʱ�� `walkTime` ���ﳵʱ�� `bikeTime`��
   - **�ȽϽ������**��ͨ�� `if - else if - else` ����ж���·ʱ����ﳵʱ��Ĵ�С��ϵ����������洢�� `comparisonResult` �����С�1 ��ʾ��·��ʱ�̣�2 ��ʾ�ﳵ��ʱ�̣�3 ��ʾ������ʱ��ͬ��
   - **`switch` ���**��ʹ�� `switch` ������ `comparisonResult` ��ֵ�����ͬ��Ϣ��`case 1` ��Ӧ��·��ʱ���̣�`case 2` ��Ӧ�ﳵ��ʱ���̣�`case 3` ��Ӧ��·���ﳵ��ʱ��ͬ��`default` ��֧�����ﲻ������

������ͨ�� `switch` ���ʵ������·���ﳵʱ��Ƚϼ��������Ĺ��ܡ� 