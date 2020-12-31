#include <bits/stdc++.h>
#define N 100005

using namespace std;

int a[N];

int partition(int a[], int n) {
	int i, j;
	i = 1;
	j = n-1;
	while(i <= j) {
		while(i < n && a[i] <= a[0]) i++;
		while(j >= i && a[j] > a[0]) j--;
		if (i < j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	i--;
	if (i > 0) {
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
	}
	return i;
}

void quicksort(int a[], int n) {
	if (n <= 1) {
		return;
	}
	int p = partition(a, n);
	quicksort(a, p);
	quicksort(a+p+1, n-p-1);
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quicksort(a, n);
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}