#include <iostream>
#include <type_traits>
#include <vector>
#include <functional>
#include <array>
#include <tuple>
#include <memory>

using namespace std;

class A {
    int x;
    char c;
    A(int _x, char _c): x{_x}, c{_c} {};
};

struct B {
    char x;
    long double ld;
};

int main() {
    cout << "char: " << alignment_of<char>::value << "\n";
    cout << "bool: " << alignment_of<bool>::value << "\n";
    cout << "short: " << alignment_of<short>::value << "\n";
    cout << "int: " << alignment_of<int>::value << "\n";
    cout << "float: " << alignment_of<float>::value << "\n";
    cout << "long: " << alignment_of<long>::value << "\n";
    cout << "long long: " << alignment_of<long long>::value << "\n";
    cout << "double: " << alignment_of<double>::value << "\n";
    cout << "string: " << alignment_of<string>::value << "\n";
    cout << "size_t: " << alignment_of<size_t>::value << "\n";
    cout << "long double: " << alignment_of<long double>::value << "\n";
    cout << "--\n";
    cout << "int*" << alignment_of<int*>::value << "\n";
    cout << "long double*: " << alignment_of<long double*>::value << "\n";
    cout << "shared_ptr<int>: " << alignment_of<shared_ptr<int>>::value << "\n";
    cout << "--\n";
    cout << "pair<char, int>: " << alignment_of<pair<char, int>>::value << "\n";
    cout << "pair<int, int>: " << alignment_of<pair<int, int>>::value << "\n";
    cout << "pair<char, double>: " << alignment_of<pair<char, double>>::value << "\n";
    cout << "--\n";
    cout << "char[]: " << alignment_of<char[]>::value << "\n";
    cout << "int[]: " << alignment_of<int[]>::value << "\n";
    cout << "--\n";
    cout << "vector<char>: " << alignment_of<vector<char>>::value << "\n";
    cout << "vector<int>: " << alignment_of<vector<int>>::value << "\n";
    cout << "vector<double>: " << alignment_of<vector<double>>::value << "\n";
    cout << "--\n";
    cout << "array<double, 3>: " << alignment_of<array<double, 3>>::value << "\n";
    cout << "--\n";
    cout << "initializer_list<char>: " << alignment_of<initializer_list<char>>::value << "\n";
    cout << "initializer_list<int>: " << alignment_of<initializer_list<int>>::value << "\n";
    cout << "--\n";
    cout << "tuple<char, bool>: " << alignment_of<tuple<char, bool>>::value << "\n";
    cout << "tuple<char, int>: " << alignment_of<tuple<char, int>>::value << "\n";
    cout << "tuple<int, double>: " << alignment_of<tuple<int, double>>::value << "\n";
    cout << "--\n";
    cout << "class A {int, char}: " << alignment_of<A>::value << "\n";
    cout << "struct B {char, long double}: " << alignment_of<B>::value << "\n";
    cout << "--\n";
    cout << "function<double(int)>: " << alignment_of<function<double(int)>>::value << "\n";
    cout << "function<int(double)>: " << alignment_of<function<int(double)>>::value << "\n";
    cout << "--\n";

    cout << "asserts testing\n";
    static_assert(is_array<array<int, 10>>::value == false);
    cout << "asserts passed\n";

    return 0;
}