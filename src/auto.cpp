#include <iostream>
#include <functional>
#include <typeinfo>

auto get_multiplier() {
    return [](int a, double b) {
        return a * b;
    };
}

int main() {
    auto multiplier = get_multiplier();
    auto result = multiplier(2, 3.5);

    std::cout << "Type of multiplier: " << typeid(multiplier).name() << std::endl;
    std::cout << "Type of result: " << typeid(result).name() << std::endl;

    int y = 10;
    std::cout << "y now is" <<y;
    auto modify_y = [&y] (){
        y = 20;
    };
    modify_y();
    std::cout << "y after is" <<y;
    return 0;
}
