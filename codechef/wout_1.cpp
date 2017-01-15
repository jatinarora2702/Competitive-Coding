#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int getmin(int *a, int n, int h){
	int minm, s;
	s = 0;
	for(int i = 0 ; i < h ; i++)
		s += a[i];
	minm = s;
	for(int i = h ; i < n ; i++){
		s += (a[i]-a[i-h]);
		if(s < minm)
			minm = s;
	}
	return minm;
}
int construct(int *st, int *a, int ss, int se, int si){
	if(ss == se){
		st[si] = a[ss];
		return st[si];
	}
	int m = (ss+se) / 2;
	st[si] = construct(st, a, ss, m, si*2+1) + construct(st, a, m+1, se, si*2+2);
	return st[si];
}
void update(int *st, int *lazy, int ss, int se, int qs, int qe, int si, int val){
	// cout << ss << " " << se << " " << qs << " " << qe << " " << si << endl;
	if(lazy[si] != 0){
		st[si] += lazy[si];
		if(ss != se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];	
		}
		lazy[si] = 0;
	}
	if(qs > se || qe < ss || ss > se)
		return;
	if(qs <= ss && se <= qe){
		st[si] += val;
		if(ss != se){
			lazy[2*si+1] = val;
			lazy[2*si+2] = val;
		}
		return;
	}
	int m = (ss+se) / 2;
	update(st, lazy, ss, m, qs, qe, 2*si+1, val);
	update(st, lazy, m+1, se, qs, qe, 2*si+2, val);
	st[si] = st[2*si+1] + st[2*si+2];
}
int getsum(int *st, int *lazy, int ss, int se, int qs, int qe, int si){
	if(lazy[si] != 0){
		st[si] += lazy[si];
		if(ss != se){
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if(qe < ss || qs > se)
		return 0;
	if(qs >= ss && qe <= se)
		return st[si];
	int m = (ss + se) / 2;
	return getsum(st, lazy, ss, m, qs, qe, 2*si+1) + getsum(st, lazy, m+1, se, qs, qe, 2*si+2);
}
int main() {
	int t, *a, *st, *lazy, n, h, minm, x, y, s;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &h);
		a = new int[n];
		st = new int[4*n];
		lazy = new int[4*n];
		for(int i = 0 ; i < n ; i++)
			a[i] = 0;
		memset(lazy, 0, sizeof lazy);
		s = construct(st, a, 0, n-1, 0);
		for(int i = 0 ; i < 4*n ; i++)
			cout << st[i] << " ";
		cout << endl;
		for(int i = 0 ; i < 4*n ; i++)
			cout << lazy[i] << " ";
		cout << endl;
		for(int i = 0 ; i < n ; i++){
			scanf("%d%d", &x, &y);
			x--, y--;
			update(st, lazy, 0, n-1, x, y, 0, 1);
		}
		cout << "Printing :\n";
		for(int i = 0 ; i < 4*n ; i++)
			cout << st[i] << " ";
		cout << endl;
		for(int i = 0 ; i < 4*n ; i++)
			cout << lazy[i] << " ";
		cout << endl;
		for(int i = 0 ; i < n ; i++)
			a[i] = getsum(st, lazy, 0, n-1, i, i, 0);
		for(int i = 0 ; i < n ; i++)
			printf("%d ", a[i]);
		cout << endl;
		minm = getmin(a, n, h);
		printf("%d\n", minm);
	}
	return 0;
}