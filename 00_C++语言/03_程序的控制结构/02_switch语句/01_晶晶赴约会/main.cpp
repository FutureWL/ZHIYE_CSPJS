#include <iostream>
#include <string>

// 判断晶晶是否有时间赴约
bool canAttendAppointment(const std::string& time) {
    // 假设晶晶周一、周三、周五晚上有时间
    if (time == "周一晚上" || time == "周三晚上" || time == "周五晚上") {
        return true;
    }
    return false;
}

int main() {
    std::string time;
    std::cout << "请输入约会时间（格式：周X晚上）: ";
    std::cin >> time;

    if (canAttendAppointment(time)) {
        std::cout << "晶晶可以赴约。" << std::endl;
    }
    else {
        std::cout << "晶晶无法赴约。" << std::endl;
    }

    return 0;
}