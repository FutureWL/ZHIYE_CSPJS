#include <iostream>
#include <cmath>
using namespace std;

// 判断一个数是否为质数的函数
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "1到100之间的质数有：" << endl;
    for (int n = 1; n <= 100; n++) {
        if (isPrime(n)) {
            cout << n << " ";
        }
    }
    cout << endl;
    return 0;
}