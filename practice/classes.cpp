#include <iostream>

using namespace std;

class A{
private:
    int a{10};
    float f{5.0};
public:
    void print() {cout << "a: " << a << " | f: " << f << "\n"; }
};

class B{
public:
    int x;
    B(int _x): x{_x} {};
    B(): B(-1) {};  // constructor can call another constructor in initializer list
};

struct C{
    int x, y, z;
    void print() {cout << "x: " << x << " | y: " << y << " | z: " << z << "\n"; }
};


int main() {
    A{}.print();

    cout << B{50}.x << "\n";
    cout << B{}.x << "\n";

    C{.x = 1, .y = 2, .z = 3}.print();
    // C{.y = 2, .z = 3, .x = 1}.print();  // does not work, cannot do out-of-order intitializtion
    
    return 0;
}