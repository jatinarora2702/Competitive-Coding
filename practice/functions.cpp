#include <iostream>

using namespace std;

template <typename A, typename B>
auto adder(A a, B b) -> decltype(a + b) {
    return a + b;
}

auto main() -> int {
    auto fn = [](int x) {
        return x + 5;
    };
    cout << fn(5) << "\n";

    cout << adder<int, float>(10, 5.5) << "\n";

    return 0;
}