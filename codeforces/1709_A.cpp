#include <iostream>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;

    while(t--) {
        cin >> s;
        for (char ch = s[0] - 1; ch >= 'a'; ch--) {
            cout << ch << s[1] << "\n";
        }
        for (char ch = s[0] + 1; ch <= 'h'; ch++) {
            cout << ch << s[1] << "\n";
        }
        for (char ch = s[1] - 1; ch >= '1'; ch--) {
            cout << s[0] << ch << "\n";
        }
        for (char ch = s[1] + 1; ch <= '8'; ch++) {
            cout << s[0] << ch << "\n";
        }
    }
    return 0;
}