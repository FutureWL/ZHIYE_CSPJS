#include <iostream>

// 函数：将整型转换为布尔型
bool intToBool(int num) {
    return num != 0;
}

// 函数：将布尔型转换为整型
int boolToInt(bool b) {
    return b ? 1 : 0;
}

int main() {
    // 整型转换为布尔型
    int intValue1 = 0;
    int intValue2 = 5;
    int intValue3 = -3;

    bool boolValue1 = intToBool(intValue1);
    bool boolValue2 = intToBool(intValue2);
    bool boolValue3 = intToBool(intValue3);

    std::cout << intValue1 << " 转换为布尔型是: " << (boolValue1 ? "true" : "false") << std::endl;
    std::cout << intValue2 << " 转换为布尔型是: " << (boolValue2 ? "true" : "false") << std::endl;
    std::cout << intValue3 << " 转换为布尔型是: " << (boolValue3 ? "true" : "false") << std::endl;

    // 布尔型转换为整型
    bool boolValue4 = true;
    bool boolValue5 = false;

    int intValue4 = boolToInt(boolValue4);
    int intValue5 = boolToInt(boolValue5);

    std::cout << "true 转换为整型是: " << intValue4 << std::endl;
    std::cout << "false 转换为整型是: " << intValue5 << std::endl;

    return 0;
}