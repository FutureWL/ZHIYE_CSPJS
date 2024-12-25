#include <iostream>

int main() {
    const char* str = "Hello world";
    size_t size = sizeof(str);
    std::cout << "字符串指针的大小: " << size << " 字节" << std::endl;

    size = sizeof("Hello world");
    std::cout << "字符串 \"Hello world\" 的大小: " << size << " 字节" << std::endl;

    return 0;
}