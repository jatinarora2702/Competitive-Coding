#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long int lli;
const int INF = 1e9 + 7;

#define N 10005

int main() {
	string s;
	int a[4], b[4], i;
	cin >> s;
	for(i = 0 ; i < 4 ; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	for(i = 0 ; i < s.length() ; i++) {
		if(s[i] == 'R')
			a[i%4] = 0;
		else if(s[i] == 'B')
			a[i%4] = 1;
		else if(s[i] == 'Y')
			a[i%4] = 2;
		else if(s[i] == 'G')
			a[i%4] = 3;
	}
	for(i = 0 ; i < s.length() ; i++) {
		if(s[i] == '!')
			b[a[i%4]]++;
	}
	for(i = 0 ; i < 4 ; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}