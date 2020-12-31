#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, k, i, j;
	string s1, s2;
	cin >> t;
	while(t--) {
		cin >> s1 >> s2;
		i = s1.length() - 1;
		j = s2.length() - 1;
		k = 0;
		while(i >= 0 && j >= 0) {
			if (s1[i] == '1' && s2[j] == '1') {
				break;
			}
			if (s1[i] == '0' && s2[j] == '1') {
				k++;
				i--;
				continue;
			}
			i--;
			j--;
		}
		cout << k << "\n";
	}
	return 0;
}