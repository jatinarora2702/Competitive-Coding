#include <bits/stdc++.h>
using namespace std;

int part(vector<int>& v) {
	int k = v[0];
	int i = 1;
	int n = v.size();
	int j = n - 1;
	while(i <= j) {
		while(i <= j && v[i] <= k) {
			i++;
		}
		while(i <= j && v[j] > k) {
			j--;
		}
		if (i < j) {
			int t = v[i];
			v[i] = v[j];
			v[j] = t;
			i++;
			j--;
		}
	}
	i--;
	if (i > 0) {
		int t = v[0];
		v[0] = v[i];
		v[i] = t;
	}
	return i;
}

void qsort(vector<int>& v) {
	int n = v.size();
	if (n <= 1) {
		return;
	}
	int p = part(v);
	vector<int> v1, v2;
	for(int i = 0; i < p; i++) {
		v1.push_back(v[i]);
	}
	for(int i = p+1; i < n; i++) {
		v2.push_back(v[i]);
	}
	qsort(v1);
	qsort(v2);
	for(int i = 0; i < v1.size(); i++) {
		v[i] = v1[i];
	}
	for(int i = 0; i < v2.size(); i++) {
		v[p+1+i] = v2[i];
	}
}

int main() {
	int a[] = {5, 6, 2, 1, 3, 4, 0, 5};
	int n = 8;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}
	qsort(v);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}