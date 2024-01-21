#include <iostream>
#include <tuple>

using namespace std;

int main() {
    int x, y;
    tie(x, y) = make_pair(10, 20);
    cout << x << ", " << y << "\n";

    string name;
    int age;
    float marks;
    tie(name, age, std::ignore, marks) = make_tuple("Henry", 19, "Biology", 96.0);
    cout << name << ", " << age << ", " << marks << "\n";

    tuple<string, int, float, bool, tuple<int, int, int>> t = make_tuple("John", 36, 10500.0, true, make_tuple(10, 2, 1977));
    cout << "Name: " << std::get<0>(t) << "\n";
    cout << "Age: " << std::get<1>(t) << "\n";
    cout << "Amount Due: " << std::get<2>(t) << "\n";
    cout << "Employed: " << std::boolalpha << std::get<3>(t) << "\n";
    cout << "DOB: " << std::get<0>(std::get<4>(t)) 
         << "/" << std::get<1>(std::get<4>(t)) 
         << "/" << std::get<2>(std::get<4>(t)) 
         << "\n";

    return 0;
}