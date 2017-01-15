#include <bits/stdc++.h>
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair < int, int > pii;

const int INF = 1e9 + 7;
const lli LINF = 1e18 + 7LL;

#define N 100005

int main() {
	int n, m;
	lli a[3];
	scanf("%d", &n);
	cin >> a[0] >> a[1] >> a[2];
	m = 4 - (n % 4);
	if(m == 1) {
		if(a[0] < 3*a[2]) {
			if(a[0] < a[2] + a[1])
				cout << a[0];
			else
				cout << a[1] + a[2];
		}
		else {
			if(3*a[2] < a[1] + a[2])
				cout << 3*a[2];
			else 
				cout << a[1] + a[2];
		}
	}
	else if(m == 2) {
		if(2*a[0] < a[1]) {
			if(2*a[0] < 2*a[2]) {
				cout << 2*a[0];
			}
			else {
				cout << 2*a[2];
			}
		}
		else {
			if(a[1] < 2*a[2]) {
				cout << a[1];	
			}
			else {
				cout << 2*a[2];
			}
		}
	}
	else if(m == 3) {
		if(3*a[0] < a[2]) {
			if(3*a[0] < a[0] + a[1]) {
				cout << 3*a[0];
			}
			else {
				cout << a[0] + a[1];
			}
		}
		else {
			if(a[2] < a[0] + a[1]) {
				cout << a[2];
			}
			else {
				cout << a[0] + a[1];
			}
		}
	}
	else {
		printf("0");
	}
	cout << endl;
	return 0;
}