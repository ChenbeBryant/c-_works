#include <iostream>

// �ص�����
void callbackFunction(int value) {
    std::cout << "Callback function called with value: " << value << std::endl;
}

// ���ܻص�������Ϊ�����ĺ���
void process(int data, void (*callback)(int)) {
    // ��������
    std::cout << "Processing data: " << data << std::endl;

    // ���ûص�����
    callback(data + 100);
}

int main() {
    // ʹ�ûص��������� process ����
    process(50, callbackFunction);

    return 0;
}
