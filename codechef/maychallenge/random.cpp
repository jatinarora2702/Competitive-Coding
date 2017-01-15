#include <bits/stdc++.h>

using namespace std;
int main() {
	srand(time(NULL));
	int n, k;
	for(int j = 0 ; j < 20 ; j++) {
	n = 1 + rand() % 20;
	k = 1 + rand() % (n);
	char *s;
	s = new char[n+1];
	for(int i = 0 ; i < n ; i++ ) {
		s[i] = rand() % 2 + 48;
	}
	s[n] = '\0';
	cout << n << " " << k << endl;
	printf("%s\n", s);
}
return 0;
}