#include <iostream>
#include <utility>  // 包含 std::move

void printLValue(int &x) {
    std::cout << "L-value reference: " << x << std::endl;
}

void printRValue(int &&x) {
    std::cout << "R-value reference: " << x << std::endl;
}

int main() {
    int a = 5;
    printLValue(a);        // 调用左值引用版本
    printRValue(10);       // 调用右值引用版本
    printRValue(std::move(a)); // 使用 std::move 将 a 转换为右值
    return 0;
}
