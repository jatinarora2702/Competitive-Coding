#include <iostream>
using namespace std;

int add(int x, int y, int mod) {
    return ((long long)(x % mod) + (y % mod)) % mod;
}

int sub(int x, int y, int mod) {
    return ((long long)(x % mod) - (y % mod) + mod) % mod;
}

int mul(int x, int y, int mod) {
    return ((long long)(x % mod) * (y % mod)) % mod;
}

int pow(int x, int p, int mod) {
    if (p == 0) {
        return 1;
    }
    long long r = pow(x, p / 2, mod);
    r = (r * r) % mod;
    if (p % 2 == 1) {
        r = (r * x) % mod;
    }
    return (int)r;
}

int inv(int x, int mod) {
    // assuming x is co-prime to mod
    return pow(x, mod - 2, mod);
}

int div(int x, int y, int mod) {
    return ((long long)(x % mod) * inv(y, mod)) % mod;
}

int main() {
    long long mod = 1e9 + 7;
    cout << add(2, 3, mod) << "\n";
    
    cout << sub(2, 3, mod) << "\n";
    cout << sub(3, 2, mod) << "\n";
    
    cout << mul(2, 3, mod) << "\n";
    
    cout << div(3, 2, mod) << "\n";
    cout << div(6, 2, mod) << "\n";
    cout << div(4, 4, mod) << "\n";

    cout << pow(2, 0, mod) << "\n";
    cout << pow(2, 5, mod) << "\n";
    cout << pow(2, 10, mod) << "\n";
    cout << pow(2, mod-2, mod) << "\n";

    return 0; 
}