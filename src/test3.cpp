#include <iostream>

// 回调函数
void callbackFunction(int value) {
    std::cout << "Callback function called with value: " << value << std::endl;
}

// 接受回调函数作为参数的函数
void process(int data, void (*callback)(int)) {
    // 处理数据
    std::cout << "Processing data: " << data << std::endl;

    // 调用回调函数
    callback(data + 100);
}

int main() {
    // 使用回调函数调用 process 函数
    process(50, callbackFunction);

    return 0;
}
