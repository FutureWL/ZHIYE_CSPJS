#include <iostream>
#include <vector>
#include <string>

// ����ѧ���ṹ��
struct Student {
    std::string name;
    std::vector<int> scores;
};

// ���ѧ���Ƿ���һ�ſβ�����
bool hasFailingGrade(const Student& student) {
    for (int score : student.scores) {
        if (score < 60) {
            return true;
        }
    }
    return false;
}

int main() {
    // ����ѧ���б�
    std::vector<Student> students = {
        {"Alice", {85, 70, 90}},
        {"Bob", {55, 75, 80}},
        {"Charlie", {70, 80, 85}}
    };

    std::cout << "��һ�ſβ������ѧ��: " << std::endl;
    for (const Student& student : students) {
        if (hasFailingGrade(student)) {
            std::cout << student.name << std::endl;
        }
    }

    return 0;
}