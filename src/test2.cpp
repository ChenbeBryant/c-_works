#include <iostream>
#include <functional>

// ����ص���������
using Callback = std::function<void()>;

// �̵���
class Store {
public:
    // ע��ص�����
    void registerCallback(Callback callback) {
        m_callback = callback;
    }

    // �������л�ʱ�����ص��¼�
    void hasStock() {
        std::cout << "�����л��ˣ�" << std::endl;
        // �����ص��¼�
        if (m_callback) {
            m_callback();
        }
    }

private:
    Callback m_callback;
};

// �˿���
class Customer {
public:
    // ���յ���Ա�ĵ绰֪ͨ
    void receiveCall() {
        std::cout << "�ӵ���Ա�ĵ绰֪ͨ��ǰ������ȡ����" << std::endl;
    }
};

int main() {
    Store store;
    Customer customer;

    // ע��ص�����
    store.registerCallback([&customer]() {
        customer.receiveCall();
    });

    // ģ������л�
    store.hasStock();

    return 0;
}
