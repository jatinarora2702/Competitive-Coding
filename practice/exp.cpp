#include <iostream>
using namespace std;

// fast exponentiation
int pow(int n, int p, int mod) {
    if (p == 0) {
        return 1;
    }
    long long r = pow(n, p / 2, mod);
    r = (r * r) % mod;
    if (p % 2 == 1) {
        r = (r * n) % mod;
    }
    return (int)r;
}

int main() {
    int mod = 1e9 + 7;
    cout << pow(0, 10, mod) << "\n";
    cout << pow(1, 10, mod) << "\n";
    cout << pow(2, 10, mod) << "\n";
    cout << pow(3, 5, mod) << "\n";
    cout << pow(3, 6, mod) << "\n";
    return 0;
}