#include <iostream>
using namespace std;

int main() {
    // 输出float类型的存储空间大小
    cout << "The size of float is " << sizeof(float) << " bytes." << endl;
    // 输出double类型的存储空间大小
    cout << "The size of double is " << sizeof(double) << " bytes." << endl;
    // 输出long double类型的存储空间大小
    cout << "The size of long double is " << sizeof(long double) << " bytes." << endl;
    return 0;
}