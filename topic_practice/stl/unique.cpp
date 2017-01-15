#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int *a, n;
	cin >> n;
	a = new int[n];
	for(int i = 0; i < n ; i++)
		cin >> a[i];
	n = unique(a, a+n) - a;
	for(int i = 0; i < n ; i++)
		cout << a[i] << " ";
	return 0;
}