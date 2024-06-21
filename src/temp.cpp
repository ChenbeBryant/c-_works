#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(10, 20) << std::endl;      // ʹ�� int ����
    std::cout << max(10.5, 20.5) << std::endl;  // ʹ�� double ����
    std::cout << max('a', 'b') << std::endl;    // ʹ�� char ����
    return 0;
}
