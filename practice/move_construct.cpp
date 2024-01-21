#include <iostream>
#include <memory>

using namespace std;

struct A {
    A() {}
    A(const A& a) { cout << "copied\n"; }
    A(A&& a) { cout << "moved\n"; }
};

template<typename T>
A wrapper(T&& t) {
    // especially invoking copy / move constructors of A
    // forward helps in invoking the light-weight "move constructor" wherever possible
    
    // return A{t};     // returns "copied" in all possible situations!
    return A{forward<T>(t)};
}

int main() {
    A a1;
    A a2 = wrapper(a1); //copied
    
    A a3 = wrapper(A{});    // moved
    
    A a4 = wrapper(move(a1));   // moved

    A a5 = wrapper(*make_unique<A>()); // copied
    // because: https://stackoverflow.com/questions/5481539/what-does-t-double-ampersand-mean-in-c11
    // auto p1 = factory<foo>(foo()); // calls foo(foo&&)
    // auto p2 = factory<foo>(*p1);   // calls foo(foo const&)

    return 0;
}