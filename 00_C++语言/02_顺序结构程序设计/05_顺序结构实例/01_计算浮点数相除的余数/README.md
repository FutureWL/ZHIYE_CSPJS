1. **ʹ��`fmod`��������׼�ⷽʽ��**��
   - ��C++�У�`<cmath>`ͷ�ļ��ṩ��`fmod`��������������������������������ú�����ԭ��Ϊ`double fmod(double x, double y)`������`x`����`y`�ĸ���������
```cpp
#include <iostream>
#include <cmath>

int main() {
    double num1 = 7.5;
    double num2 = 2.5;
    double result = fmod(num1, num2);
    std::cout << num1 << " ���� " << num2 << " ��������: " << result << std::endl;
    return 0;
}
```
   - �����������У�����������`double`���͵ĸ�����`num1`��`num2`��Ȼ��ʹ��`fmod`��������`num1`����`num2`��������������������

2. **�Զ���ʵ�ָ��������ࣨԭ��չʾ��**��
   - �����������ԭ����ͨ��������ȥ������ֱ�����С�ڳ�����������һ���򵥵��Զ���ʵ�֣�
```cpp
#include <iostream>

double customFmod(double x, double y) {
    while (x >= y) {
        x -= y;
    }
    return x;
}

int main() {
    double num1 = 7.5;
    double num2 = 2.5;
    double result = customFmod(num1, num2);
    std::cout << num1 << " ���� " << num2 << " ��������: " << result << std::endl;
    return 0;
}
```
   - ������Զ��庯��`customFmod`�У�ͨ��һ��`while`ѭ�����ϴ�`x`�м�ȥ`y`��ֱ��`x`С��`y`����ʱ��`x`������������`main`�����е�������Զ��庯�������㲢���������

��Ҫע����ǣ����ڸ������ڼ�����еĴ洢��ʽ��������������ܻ���ھ������⡣���磬����һЩ���Ƽ򵥵ĸ��������㣬���������Ԥ������ƫ���ʵ��Ӧ���У�����Ծ���Ҫ��ϸߣ�������Ҫ����Ĵ��� 