#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int a[N], b[N], h[N], as1, as2;

void myspread(int ps, int pe, int cs, int ce) {
	int cc = cs;
	int pc = ps;
	as1 = 0;
	while(cc <= ce) {
		a[cc] = pc;
		as1 = max(as1, pc);
		cc++;
		pc = ps + ((pc - ps + 1) % (pe - ps + 1));
	}
}

void mycollate(int ps, int pe, int cs, int ce) {
	int cc = cs;
	int pc = ps;
	as2 = 0;
	while(cc <= ce) {
		b[cc] = pc;
		as2 = max(as2, pc);
		// pc += (cc - cs) % 2;
		cc++;
	}
}

int main() {
	int n, i, j, k, f;
	scanf("%d", &n);
	for(i = 0 ; i <= n ; i++)
		scanf("%d", &h[i]);
	a[0] = b[0] = -1;
	f = 0;
	k = 1;
	for(i = 1 ; i <= n ; i++) {
		myspread(k - h[i - 1], k - 1, k, k + h[i] - 1);
		mycollate(k - h[i - 1], k - 1, k, k + h[i] - 1);
		k += h[i];
		if (f == 0 && as1 != as2) {
			f = 1;
		}
	}
	if (f == 0) {
		printf("perfect\n");
	}
	else {
		printf("ambiguous\n");
		for(i = 0 ; i < k ; i++)
			printf("%d ", a[i] + 1);
		printf("\n");
		for(i = 0 ; i < k ; i++)
			printf("%d ", b[i] + 1);
		printf("\n");
	}
	return 0;
}