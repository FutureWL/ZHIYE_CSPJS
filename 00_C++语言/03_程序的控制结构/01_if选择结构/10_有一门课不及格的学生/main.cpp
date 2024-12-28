#include <iostream>
#include <vector>
#include <string>

// 定义学生结构体
struct Student {
    std::string name;
    std::vector<int> scores;
};

// 检查学生是否有一门课不及格
bool hasFailingGrade(const Student& student) {
    for (int score : student.scores) {
        if (score < 60) {
            return true;
        }
    }
    return false;
}

int main() {
    // 创建学生列表
    std::vector<Student> students = {
        {"Alice", {85, 70, 90}},
        {"Bob", {55, 75, 80}},
        {"Charlie", {70, 80, 85}}
    };

    std::cout << "有一门课不及格的学生: " << std::endl;
    for (const Student& student : students) {
        if (hasFailingGrade(student)) {
            std::cout << student.name << std::endl;
        }
    }

    return 0;
}