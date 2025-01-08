#include <coroutine>
#include <iostream>
#include <optional>

// 定义一个协程返回类型
struct IntGenerator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        int current_value;

        IntGenerator get_return_object() {
            return IntGenerator{handle_type::from_promise(*this)};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }

        void unhandled_exception() {
            std::terminate();
        }

        void return_void() {}
    };

    class iterator {
        handle_type h_;
    public:
        iterator(handle_type h) : h_(h) {}
        bool operator != (std::nullopt_t) const { return !h_.done(); }
        void operator ++() { h_.resume(); }
        int operator *() const { return h_.promise().current_value; }
    };

    handle_type h_;

    IntGenerator(handle_type h) : h_(h) {}
    ~IntGenerator() { if(h_) h_.destroy(); }

    iterator begin() { return iterator{h_}; }
    std::nullopt_t end() { return {}; }
};

IntGenerator generate_integers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        co_yield i;
    }
}

int main() {
    for (int num : generate_integers(1, 5)) {
        std::cout << num << std::endl;
    }
}