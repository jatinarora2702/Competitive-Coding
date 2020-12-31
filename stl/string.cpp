#include <bits/stdc++.h>
using namespace std;

int main() {
	// learning difference between normal string input and cin.getline (which allows strings with spaces too!), string.getline()

	// string s1, s2, s3;
	// int num;
	// cin >> s1 >> s2 >> s3 >> num;	// does not accept blank string input (just pressing <enter>)
	// cout << "[" << s1 << "]\n";
	// cout << "[" << s2 << "]\n";
	// cout << "[" << s3 << "]\n";
	// cout << num << "\n";


	// getline(cin, s1);	// accepts blank string inputs (just pressing <enter>), accepts leading and trailing spaces, only spaces in string, spaces within strings too..
	// getline(cin, s2);
	// getline(cin, s3);
	// cin >> num;
	// cout << "[" << s1 << "]\n";
	// cout << "[" << s2 << "]\n";
	// cout << "[" << s3 << "]\n";
	// cout << num << "\n";

	char a[12], b[20];
	
	// cin >> a >> b;
	// cout << "[" << a << "]" << "\n";
	// cout << "[" << b << "]" << "\n";
	
	// this function is overloaded for strings (the one we experimented with above!)
	cin.getline(a, 12);
	cin.getline(b, 20);
	cout << "[" << a << "]" << "\n";
	cout << "[" << b << "]" << "\n";

	return 0;
}