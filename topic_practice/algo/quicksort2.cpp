#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int s, int e) {
	int i = s+1;
	int j = e;
	while(i <= j) {
		if (a[i] <= a[s]) {
			i++;
		}
		else if (a[j] > a[s]) {
			j--;
		}
		else {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	i--;
	int t = a[i];
	a[i] = a[s];
	a[s] = t;
	return i;
}

void quick(vector<int>& a, int s, int e) {
	if (s >= e) {
		return;
	}
	int p = partition(a, s, e);
	quick(a, s, p-1);
	quick(a, p+1, e);
}

vector<int> inp() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	return a;
}

void out(vector<int>& a) {
	for(int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {
	vector<int> a = inp();
	quick(a, 0, a.size()-1);
	out(a);
	return 0;
}