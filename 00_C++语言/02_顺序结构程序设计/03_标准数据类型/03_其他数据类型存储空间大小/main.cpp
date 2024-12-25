#include <iostream>
using namespace std;

// 定义一个简单的结构体
struct MyStruct {
    int a;
    char b;
};

// 定义一个联合体
union MyUnion {
    int a;
    char b;
};

int main() {
    // 输出bool类型的大小
    cout << "The size of bool is " << sizeof(bool) << " bytes." << endl;
    // 输出char*类型的大小
    cout << "The size of char* is " << sizeof(char*) << " bytes." << endl;
    // 输出结构体MyStruct的大小
    cout << "The size of MyStruct is " << sizeof(MyStruct) << " bytes." << endl;
    // 输出联合体MyUnion的大小
    cout << "The size of MyUnion is " << sizeof(MyUnion) << " bytes." << endl;
    return 0;
}