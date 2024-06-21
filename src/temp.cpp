#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(10, 20) << std::endl;      // 使用 int 类型
    std::cout << max(10.5, 20.5) << std::endl;  // 使用 double 类型
    std::cout << max('a', 'b') << std::endl;    // 使用 char 类型
    return 0;
}
