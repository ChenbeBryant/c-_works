#include <iostream>
#include <functional>

// 定义回调函数类型
using Callback = std::function<void()>;

// 商店类
class Store {
public:
    // 注册回调函数
    void registerCallback(Callback callback) {
        m_callback = callback;
    }

    // 当店里有货时触发回调事件
    void hasStock() {
        std::cout << "店里有货了！" << std::endl;
        // 触发回调事件
        if (m_callback) {
            m_callback();
        }
    }

private:
    Callback m_callback;
};

// 顾客类
class Customer {
public:
    // 接收到店员的电话通知
    void receiveCall() {
        std::cout << "接到店员的电话通知，前往店里取货。" << std::endl;
    }
};

int main() {
    Store store;
    Customer customer;

    // 注册回调函数
    store.registerCallback([&customer]() {
        customer.receiveCall();
    });

    // 模拟店里有货
    store.hasStock();

    return 0;
}
