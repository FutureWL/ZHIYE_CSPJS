#include <iostream>
#include <string>

int main() {
    std::string time;
    std::cout << "请输入约会时间（格式：周X晚上）: ";
    std::cin >> time;

    int dayIndex = -1;
    if (time == "周一晚上") {
        dayIndex = 1;
    }
    else if (time == "周二晚上") {
        dayIndex = 2;
    }
    else if (time == "周三晚上") {
        dayIndex = 3;
    }
    else if (time == "周四晚上") {
        dayIndex = 4;
    }
    else if (time == "周五晚上") {
        dayIndex = 5;
    }
    else if (time == "周六晚上") {
        dayIndex = 6;
    }
    else if (time == "周日晚上") {
        dayIndex = 7;
    }

    switch (dayIndex) {
    case 1:
    case 3:
    case 5:
        std::cout << "晶晶可以赴约。" << std::endl;
        break;
    default:
        std::cout << "晶晶无法赴约。" << std::endl;
        break;
    }

    return 0;