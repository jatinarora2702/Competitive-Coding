#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define N 100005

using namespace std;

int a[N];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cout << a[(i+1) % n] << " ";
	}
	cout << "\n";
	return 0;
}
