#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// 主模板类，计算 n 的阶乘
template <unsigned int N>
class Factorial {
    public:
    static const unsigned long long value = N * Factorial<N - 1>::value;
} ;

// 特化模板类，处理 n = 0 的情况
template <>
struct Factorial<0> {
    public:
    static const unsigned long long value = 1;
};

int main() {
    std::cout << max(10, 20) << std::endl;      // 使用 int 类型
    std::cout << max(10.5, 20.5) << std::endl;  // 使用 double 类型
    std::cout << max('a', 'b') << std::endl;    // 使用 char 类型
    std::cout << "Facor of  5 is" << Factorial<5>::value << std::endl;
    return 0;
}
