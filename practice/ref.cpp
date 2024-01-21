#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int val = 99;
    std::reference_wrapper<int> my_ref = std::ref(val);
    std::reference_wrapper<const int> my_cref = std::cref(val);
    cout << val << "\n";
    cout << my_ref << "\n";
    my_ref++;
    cout << my_cref << "\n";
    cout << val << "\n";
    return 0;
}