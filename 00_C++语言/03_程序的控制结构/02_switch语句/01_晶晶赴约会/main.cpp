#include <iostream>
#include <string>

// �жϾ����Ƿ���ʱ�丰Լ
bool canAttendAppointment(const std::string& time) {
    // ���辧����һ������������������ʱ��
    if (time == "��һ����" || time == "��������" || time == "��������") {
        return true;
    }
    return false;
}

int main() {
    std::string time;
    std::cout << "������Լ��ʱ�䣨��ʽ����X���ϣ�: ";
    std::cin >> time;

    if (canAttendAppointment(time)) {
        std::cout << "�������Ը�Լ��" << std::endl;
    }
    else {
        std::cout << "�����޷���Լ��" << std::endl;
    }

    return 0;
}