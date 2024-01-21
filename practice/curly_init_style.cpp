#include <iostream>
#include <array>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Point {
public:
    int x, y;
    string desc;
    Point(int _x, int _y, const string& _desc): x{_x}, y{_y}, desc{_desc} {};    
    // Point(int _x, int _y, const string& _desc): x(_x), y(_y), desc(_desc) {};   // also works   
};

int main() {
    // bottomline:
    // many initialization ways exist
    // use judgement call to decide which is cleanest in a given situation 
    // https://stackoverflow.com/questions/18222926/what-are-the-advantages-of-list-initialization-using-curly-bracess

    // int
    int a{5};
    cout << a << "\n";

    // int ptr (dynamic allocation)
    int* p1 = new int{10};
    cout << *p1 << "\n";

    // int ptr (dynamic allocation)
    int* p2 = new int{};    // no init style
    *p2 = 15;
    cout << *p2 << "\n";

    // array init
    int arr[3]{-1, -2, -3};
    cout << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n";

    // array ptr init
    int* p_arr = new int[3]{-10, -20, -30};
    cout << p_arr[0] << ", " << p_arr[1] << ", " << p_arr[2] << "\n";

    // vector init
    vector<int> v{{1, 2, 3, 4, 5}};
    for(const int& val: v) {
        cout << val << " ";
    }
    cout << "\n";

    // vector init (default empty)
    vector<int> v_empty{};  // no init style
    cout << v_empty.size() << "\n"; //0

    // 2D vector init
    vector<vector<int>> mat{{{1, 2}, {3, 4}}};
    for(const vector<int>& row: mat) {
        for(const int& val: row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "---\n";

    // pair init
    pair<int, float> p{10, 20.5};
    cout << p.first << ", " << p.second << "\n";

    // string init
    string s{"abcd is\nmy name"};
    cout << s << "\n";

    // char inits
    char c{'x'};
    cout << c << "\n";

    // user-defined class init
    Point point{-1, -2, "bot location"};
    cout << point.x << ", " << point.y  << ", " << point.desc << "\n";

    // user-defined class ptr handling (style 1)
    unique_ptr<Point> point_ptr1 = make_unique<Point>(10, 20, "ptr1 location");
    cout << point_ptr1->x << ", " << point_ptr1->y << ", " << point_ptr1->desc << "\n";

    // user-defined class ptr handling (style 2)
    unique_ptr<Point> point_ptr2 = make_unique<Point>(Point{100, 200, "ptr2 location"});
    cout << point_ptr2->x << ", " << point_ptr2->y << ", " << point_ptr2->desc << "\n";

    // STL array - dynamic ptr allocation
    unique_ptr<array<int, 3>> ap1 = make_unique<array<int, 3>>(array<int, 3>{{5, 6, 7}});
    for (const int& val: *ap1) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}