#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	string s = "ABCDEF";
	for(int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	for(int i = 0; i < 10; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	cout << "orig: " << s << "\n";
	reverse(s.begin(), s.end());	// wow! works! cool!
	cout << "new: " << s << "\n";
	return 0;
}
