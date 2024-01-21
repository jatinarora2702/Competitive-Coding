#include <iostream>

namespace a {
    void fn1() {
        std::cout << "a-fn1\n";
    }
}

namespace b {
    void fn1() {
        std::cout << "b-fn1\n";
    }
}


int main() {
    a::fn1();
    b::fn1();

    std::cout << "std::cout\n";

    // after this, I can omit std::
    using namespace std;
    cout << "cout\n";

    return 0;
}