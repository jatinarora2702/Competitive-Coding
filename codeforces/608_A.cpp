#include <bits/stdc++.h>
#define FF first
#define SS second
#define N 105
using namespace std;
pair < int, int > pr[N];
bool fn(pair < int ,int > p1, pair < int, int > p2){
	return p1.FF > p2.FF;
}
int main() {
	int n, s, x, y, t, p;
	scanf("%d%d", &n, &s);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &pr[i].FF, &pr[i].SS);
	}
	sort(pr, pr+n, fn);
	p = s;
	t = 0;
	for(int i= 0  ; i < n ; i++){
		t += (p - pr[i].FF);
		p = pr[i].FF;
		if(t < pr[i].SS)
			t = pr[i].SS;
	}
	t += p;
	printf("%d", t);
	return 0;
}