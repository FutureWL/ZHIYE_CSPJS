#include <iostream>
#include <string>
using namespace std;

int main() {
    string password = "1234";  // 假设的正确密码，实际应用中这是未知的
    cout << "开始尝试破解密码..." << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    string guess = to_string(i) + to_string(j) + to_string(k) + to_string(l);
                    if (guess == password) {
                        cout << "密码破解成功，密码是：" << guess << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "密码破解失败" << endl;
    return 0;
}