#include <map>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

using namespace std;

template <typename T>
using CounterMap = unordered_map<T, int>;

int main() {
    map<int, int> doubles{{2, 4}, {3, 6}, {4, 8}};
    doubles.insert({6, 12});
    doubles.insert({{10, 20}, {20, 40}});
    doubles.insert(make_pair(18, 36));
    doubles[90] = 180;

    // non-existent key (gets added, value defaulted to 0)
    cout << doubles[5] << "\n"; //0

    cout << std::boolalpha << doubles.contains(8) << "\n";  //false
    
    // key insertion styles - testing
    cout << doubles.at(6) << "\n";  //12
    cout << doubles.at(10) << "\n"; //20
    cout << doubles.at(20) << "\n"; //40
    cout << doubles.at(18) << "\n"; //36
    cout << doubles.at(90) << "\n"; //180
    
    // exception using at() when key not found
    try {
        cout << doubles.at(8) << "\n";
    } catch (const out_of_range& err) {
        cerr << err.what() << "\n";
    }

    CounterMap<string> cmap;
    for(const string& s: {"this", "a", "that", "a", "boy"}) {
        cmap[s] += 1;
    }
    for(const auto &[word, count]: cmap) {
        cout << "word: " << word << " | count: " << count << "\n";
    }

    return 0;
}