#include <bits/stdc++.h>
using namespace std;
 
#define N 311111
#define A 1111111
#define NUM 555 // ~sqrt(N)
 
int cnt[A], a[N], ans[N], ans = 0;
 
struct tree_node {
	int L, R, i;
}q[N];
 
bool cmp(tree_node x, tree_node y) {
	if(x.L/NUM != y.L/NUM) {
		// different blocks, so sort by NUM.
		return x.L/NUM < y.L/NUM;
	}
	// same NUM, so sort by R value
	return x.R < y.R;
}
 
void add(int p) {
	cnt[a[p]]++;
	if(cnt[a[p]] == 1) {
		ans++;
	}
}
 
void remove(int p) {
	cnt[a[p]]--;
	if(cnt[a[p]] == 0) {
		ans--;
	}
}
 
int main() {
	int n,m,type;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	//sort(q, q + m, cmp);
 
	int currentL = 0, curr_ = 0;
	for(int i=0; i<m; i++) {
		scanf("%d%d%d",&type, &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
		if(type!=5)
			return 0;
 
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(curr_ <= R) {
			add(curr_);
			curr_++;
		}
		while(curr_ > R+1) {
			remove(curr_-1);
			curr_--;
		}
		printf("%d\n",ans);
		//ans[q[i].i] = ans;
	}
	return 0;
}