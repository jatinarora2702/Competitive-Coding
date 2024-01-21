#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // --- to str
    cout << to_string(10) << "\n";
    cout << to_string(10.5) << "\n";    //10.500000 <- can have unexpected round-offs too
    cout << to_string(true) << "\n";    //1
    cout << to_string('a') << "\n"; //97 <- ascii num conversion

    // bool to str
    stringstream ssb;
    ssb << boolalpha << true;
    string sb = ssb.str();
    cout << sb << "\n";  //true

    // float to str (slower than to_string(), but accurate)
    // (works for int, double and other data types too)
    stringstream ssf1, ssf2;
    ssf1 << 10.5;
    ssf2 << 1e-9;
    string sf1(ssf1.str());
    string sf2(ssf2.str());
    cout << sf1 << "\n";    //10.5
    cout << sf2 << "\n";    //1e-09 <- note the difference!

    //-----------------------------------------------------

    // str to ---
    cout << stod("10.5") + 1.0 << "\n"; //11.5
    cout << stoi("10") + 5 << "\n"; //15
    
    // str to bool
    bool b;
    istringstream("true") >> boolalpha >> b;
    cout << boolalpha << !b << "\n";    //false

    // str to float, int
    int n;
    float f;
    istringstream("20") >> n;
    istringstream("1.12e-3") >> f;
    cout << n + 5 << "\n";  //25
    cout << f + 2.0 << "\n";    //2.00112

    // str to char breakdown
    string sent("this");
    cout << sent[0] << "\n";    //t
    cout << sent[0] - 't' << "\n";  //0

    // char to str buildup
    string tmp;
    for(const int& ch: initializer_list<char>{'a', 'b', 'c'}) { //efficient <- note*
        tmp += ch;
    }
    cout << tmp << "\n";    //abc

    // note*: initilizer_list is better than a vector
    // for initializations and temporary work if
    // values are statically known! memory allocation is
    // optimized and dynamic allocation on heap which happens
    // for vectors can be avoided in this way.
    //
    // Tried but could not pass raw arrays here. Eg:
    // for( ...: char[]{'a', 'b'}) <- is not alloweds

    // Simplest:
    // if all chars to join into a string are statically known
    cout << string({'t', 'o', 'p'}) << "\n";

    // raw string literals
    cout << R"(This is a string
        in two lines\n)";

    return 0;
}