#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int x1, x2;
	int a[105], b[105];
	string s1, s2;
	s1 = "? ";
	for(int i = 1; i <= 100; i++) {
		a[i-1] = i;
		s1 += to_string(a[i-1]) + " ";
	}
	s2 = "? ";
	for(int i = 1; i <= 100; i++) {
		b[i-1] = i << 7;
		s2 += to_string(b[i-1]) + " ";
	}
	cout << s1 << "\n";
	fflush(stdout);
	cin >> x1;
	cout << s2 << "\n";
	fflush(stdout);
	cin >> x2;
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			if((a[i] ^ b[j]) == (x1 ^ x2)) {
				cout << "! " << (x1 ^ a[i]) << "\n";
				return 0;
			}
		}
	}
	return 1;
}