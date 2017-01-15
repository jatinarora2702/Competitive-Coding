#include <bits/stdc++.h>
#define N 505
using namespace std;
typedef long long int lli;
lli a[N][N];
int n;

int check(lli exps) {
	int i, j;
	lli s;
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++) {
			if(a[i][j] <= 0) {
				return 0;
			}
		}
	}
	for(i = 0 ; i < n ; i++) {
		s = 0LL;
		for(j = 0 ; j < n ; j++) {
			s += a[i][j];
		}
		if(s != exps) {
			return 0;
		}
	}
	for(j = 0 ; j < n ; j++) {
		s = 0LL;
		for(i = 0 ; i < n ; i++) {
			s += a[i][j];
		}
		if(s != exps) {
			return 0;
		}
	}
	s = 0LL;
	for(i = 0 ; i < n ; i++) {
		s += a[i][i];
	}
	if(s != exps) {
		return 0;
	}
	s = 0LL;
	for(i = 0 ; i < n ; i++) {
		s += a[i][n-i-1];
	}
	if(s != exps) {
		return 0;
	}
	return 1;
}

int main() {
	int i, j, f, flag;
	lli s, anss, news;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++) {
		for(j = 0 ; j < n ; j++) {
			cin >> a[i][j];
		}
	}
	if(n == 1) {
		a[i][j] = 1;
		printf("1\n");
		return 0;
	}
	f = -1;
	for(i = 0 ; i < n ; i++) {
		s = 0LL;
		flag = 0;
		for(j = 0 ; j < n ; j++) {
			if(a[i][j] == 0) {
				f = i;
				flag = 1;
			}
			s += a[i][j];
		}
		if(flag == 0) {
			anss = s;
		}
		else if(flag == 1) {
			news = s;
		}
	}
	if(news >= anss) {
		printf("-1\n");
	}
	else {
		for(j = 0 ; j < n ; j++) {
			if(a[f][j] == 0) {
				a[f][j] = anss - news;
			}
		}
		f = check(anss);
		if(f == 0) {
			printf("-1\n");
		}
		else {
			cout << anss - news << endl;
		}
	}
	return 0;
}