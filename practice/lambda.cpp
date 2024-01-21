#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Marks {
public:
    int val;
    Marks(int _val): val{_val} {};
    void fn(int);
};

void Marks::fn(int x) {
    cout << ([this](int p) {
        this->val--;    // this is captured by ref here. Modification allowed.
        return this->val * p;
    })(x) << "\n";
}

int main() {
    function<vector<int>(int)> table = [](const int& p) noexcept -> vector<int> {
        // return {p, p*2, p*3, p*4, p*5};
        return vector<int>({p, p*2, p*3, p*4, p*5});
    };

    int p;
    cin >> p;   // user input. Will print its table.
    for(const int& val: table(p)) {
        cout << val << " ";
    }
    cout << "\n";

    // create a lambda and use it in same line
    // notice extra brackets around lambda (required)
    int x = 5, y = 10;
    cout << ([x, y](int mx, int my) noexcept -> int {return (x * mx) + (y * my); })(1, 2) << "\n";  //25

    // this
    Marks m(10);
    m.fn(2);    //18
    
    return 0;
}