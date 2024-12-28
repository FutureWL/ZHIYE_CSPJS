������һ���򵥵�C++ ����������ģ���ҳ���һ�ſβ����񣨼���ɼ�С��60��Ϊ�����񣩵�ѧ�������Ǽ�����һ���༶��ÿ��ѧ����һ�������Ͷ�Ӧ�Ķ��ſγ̳ɼ���

```cpp
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
```

### ������ͣ�
1. **�ṹ�嶨��**��
    - `Student` �ṹ�����ڴ洢ѧ���������ͳɼ���`name` �� `std::string` ���ͣ�`scores` �� `std::vector<int>` ���ͣ����ڴ洢���ſγ̵ĳɼ���
2. **��������**��
    - `hasFailingGrade` ��������һ�� `Student` �ṹ���������Ϊ������ͨ������ѧ���ĳɼ��б���������гɼ�С��60�֣��򷵻� `true`����ʾ��ѧ����һ�ſβ����񣻷��򷵻� `false`��
3. **������**��
    - �� `main` �����У�������һ���������ѧ����Ϣ�� `students` ������
    - ���� `students` ��������ÿ��ѧ������ `hasFailingGrade` �������м�顣���ѧ����һ�ſβ������������ѧ����������

����������Ը���ʵ�����������չ��������ļ��ж�ȡѧ����Ϣ��������Ӹ���Ŀγ̺Ͳ�����