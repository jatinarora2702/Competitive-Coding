#include <functional>   // for hash
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

struct TTime {
    int hrs, min, sec;
    TTime(int _hrs, int _min, int _sec): hrs{_hrs}, min{_min}, sec{_sec} {};
    bool operator<(const TTime& t) const {
        if (hrs == t.hrs) {
            if (min == t.min) {
                return sec < t.sec;
            }
            return min < t.min;
        }
        return hrs < t.hrs;
    }
    bool operator==(const TTime& t) const {
        return hrs == t.hrs && min == t.min && sec == t.sec;
    }
};

// Overloading the hash class for our custom class.
// This makes the class directly usable in hash-based STL containers.
template<>
struct std::hash<TTime> {
    size_t operator()(const TTime& t) const noexcept {
        size_t h = 0;
        // 12345 is any randomly selected constant here
        h ^= std::hash<int>()(t.hrs) + 12345 + (h << 6) + (h >> 2);
        h ^= std::hash<int>()(t.min) + 12345 + (h << 6) + (h >> 2);
        h ^= std::hash<int>()(t.sec) + 12345 + (h << 6) + (h >> 2);
        return h;
    }
};

struct Age {
    int val;
    string name;
    Age(int _val, string _name): val(_val), name(_name) {};
};

struct AgeCompareLess {
    bool operator()(const Age& lhs, const Age& rhs) const {
        return lhs.val < rhs.val;
    }
};

struct AgeCompareEqual {
    bool operator()(const Age& lhs, const Age& rhs) const noexcept {
        return lhs.val == rhs.val;
    }
};

struct AgeHash {
    size_t operator()(const Age& a) const noexcept {
        // For (A, B, C), can also do something like:
        // val = H(A)
        // val = (val >> 1) ^ (H(B) << 1)
        // val = (val >> 1) ^ (H(C) << 1) ...
        return std::hash<int>()(a.val);
    }
};

// This fn does not check at compile time
// C++20 has 'concept' that can do that.
template <typename TTimeContainer>
void ttime_printer(const TTimeContainer& container) {
    cout << "size: " << container.size() << " | ";
    for(const TTime& t: container) {
        cout << "(" << t.hrs << ", " << t.min << ", " << t.sec << ") ";
    }
    cout << "\n";
}

template <typename AgeContainer>
void age_printer(const AgeContainer& container) {
    cout << "size: " << container.size() << " | ";
    for(const Age& a: container) {
        cout << "(" << a.val << ", " << a.name << ") ";
    }
    cout << "\n";
}

int main() {
    set<TTime> st1;
    st1.insert(TTime(1, 20, 0));
    st1.insert(TTime(1, 40, 0));
    st1.insert(TTime(0, 20, 0));
    ttime_printer(st1);

    unordered_set<TTime> ust1;
    ust1.insert(TTime(1, 20, 0));
    ust1.insert(TTime(1, 40, 0));
    ust1.insert(TTime(0, 20, 0));
    ttime_printer(ust1);

    set<Age, AgeCompareLess> st2;
    st2.insert(Age(10, "a"));
    st2.insert(Age(15, "b"));
    st2.insert(Age(20, "c"));
    st2.insert(Age(10, "d"));   //ignored
    age_printer(st2);

    unordered_set<Age, AgeHash, AgeCompareEqual> ust2;
    ust2.insert(Age(10, "a"));
    ust2.insert(Age(15, "b"));
    ust2.insert(Age(20, "c"));
    age_printer(ust2);

    cout << std::boolalpha << (st1.find(TTime(0, 20, 0)) != st1.end()) << "\n";
    st1.erase(TTime(0, 20, 0));
    cout << std::boolalpha << (st1.find(TTime(0, 20, 0)) != st1.end()) << "\n";

    cout << std::boolalpha << ust1.contains(TTime(1, 20, 0)) << "\n";
    cout << std::boolalpha << ust2.contains(Age(15, "unknown")) << "\n";    //true

    unordered_multiset<Age, AgeHash, AgeCompareEqual> umst1;
    umst1.insert(Age(10, "a"));
    umst1.insert(Age(20, "b"));
    umst1.insert(Age(10, "c")); //not ignored
    age_printer(umst1);

    cout << std::boolalpha << umst1.contains(Age(10, "e")) << "\n"; //true
    cout << umst1.count(Age(10, "unk")) << "\n";    //2
    umst1.erase(Age(10, "c"));
    cout << std::boolalpha << umst1.contains(Age(10, "e")) << "\n"; //false <- all removed with equal Age.val

    return 0;
}