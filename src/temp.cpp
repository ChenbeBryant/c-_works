#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// ��ģ���࣬���� n �Ľ׳�
template <unsigned int N>
class Factorial {
    public:
    static const unsigned long long value = N * Factorial<N - 1>::value;
} ;

// �ػ�ģ���࣬���� n = 0 �����
template <>
struct Factorial<0> {
    public:
    static const unsigned long long value = 1;
};

int main() {
    std::cout << max(10, 20) << std::endl;      // ʹ�� int ����
    std::cout << max(10.5, 20.5) << std::endl;  // ʹ�� double ����
    std::cout << max('a', 'b') << std::endl;    // ʹ�� char ����
    std::cout << "Facor of  5 is" << Factorial<5>::value << std::endl;
    return 0;
}
