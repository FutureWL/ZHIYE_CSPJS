以下是一个简单的C++ 案例，用于模拟找出有一门课不及格（假设成绩小于60分为不及格）的学生。我们假设有一个班级，每个学生有一个姓名和对应的多门课程成绩。

```cpp
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
```

### 代码解释：
1. **结构体定义**：
    - `Student` 结构体用于存储学生的姓名和成绩。`name` 是 `std::string` 类型，`scores` 是 `std::vector<int>` 类型，用于存储多门课程的成绩。
2. **函数定义**：
    - `hasFailingGrade` 函数接受一个 `Student` 结构体的引用作为参数。通过遍历学生的成绩列表，如果发现有成绩小于60分，则返回 `true`，表示该学生有一门课不及格；否则返回 `false`。
3. **主函数**：
    - 在 `main` 函数中，创建了一个包含多个学生信息的 `students` 向量。
    - 遍历 `students` 向量，对每个学生调用 `hasFailingGrade` 函数进行检查。如果学生有一门课不及格，则输出该学生的姓名。

这个案例可以根据实际需求进行扩展，例如从文件中读取学生信息，或者添加更多的课程和操作。