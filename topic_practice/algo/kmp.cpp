#include <bits/stdc++.h>
#define N 100005
using namespace std;

int pre[N], n, m;
vector < int > v;

string s, p;

void calcpre() {
	int i, j;
	pre[0] = -1;
	i = 1;
	j = 0;
	while(i < m) {
		if (p[i] == p[j]) {
			pre[i] = j;
			i++;
			j++;
		}
		else {
			if (j >= 0) {
				j = pre[j];
			}
			else {
				pre[i] = -1;
				i++;
				j = 0;
			}
		}
	}
}

int main() {
	int i, j;
	cin >> s >> p;
	n = s.length();
	m = p.length();
	calcpre();
	i = 0;
	j = 0;
	while(i < n) {
		if (s[i] == p[j]) {
			if (j == m-1) {
				v.push_back(i-j);
				j = pre[j] + 1;
			}
			else {
				j++;
			}
			i++;
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				j = pre[j-1] + 1;
			}
		}
	}
	for(int l = 0; l < v.size(); l++) {
		cout << v[l] << " ";
	}
	cout << "\n";
	return 0;
}