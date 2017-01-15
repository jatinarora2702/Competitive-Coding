#include <bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long int lli;
const lli INF = 1e15 + 7LL;
int a[N];
lli  b[2][N];
int main() {
	int t, i, j, f, start, end, n, p[2][2];
	lli sm[2][2], s, stemp, temp, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%d%d", &start, &end);
		start--;
		end--;
		// printf("start=%d | end=%d\n", start, end);
		ans = INF;
		sm[0][0] = sm[0][1] = sm[1][0] = sm[1][1] = INF;
		p[0][0] = p[0][1] = p[1][0] = p[1][1] = -1;
		s = 0LL;
		f = 0;
		j = start;
		temp = INF;
		if(f == 0 && sm[0][0] > s) {
			sm[0][0] = s;
			p[0][0] = j;
			// printf("j=%d | f=%d | sm=%lld | p=%d | ans=%lld\n", j, f, sm[0][0], p[0][0], ans);
		}
		for(i = 1 ; i <= n ; i++) {
			s += (lli)a[j];
			// printf("j=%d\n", j);
			if(f == 0 && sm[0][0] > s) {
				sm[0][0] = s;
				p[0][0] = (j+1)%n;
				// printf("j=%d | f=%d | sm=%lld | p=%d | ans=%lld\n", (j+1)%n, f, sm[0][0], p[0][0], ans);
			}
			if(f == 1) {
				stemp += (lli)a[j];
				ans = min(ans, s+stemp);
				b[0][(j+1)%n] = min(temp, s+stemp);
				temp = b[0][(j+1)%n];
				if(sm[0][1] > s) {
					sm[0][1] = s;
					p[0][1] = (j+1)%n;
				}
				// printf("j=%d | f=%d | sm=%lld | p=%d | ans=%lld | s+stemp=%lld | bmin=%lld\n", (j+1)%n, f, sm[0][1], p[0][1], ans, s+stemp, b[0][(j+1)%n]);
			}
			j++;
			j %= n;
			if(j == end){
				ans = min(ans, s);
				b[0][j] = min(temp, s);
				temp = b[0][j];
				stemp = 0LL;
				f = 1;
			}
		}
		sm[0][0] *= 2LL;
		// printf("\n------------------\n");
		s = 0LL;
		f = 0;
		j = start;
		temp = INF;
		if(f == 0 && sm[1][0] > s) {
			sm[1][0] = s;
			p[1][0] = j;
			// printf("j=%d | f=%d | sm=%lld | p=%d | ans=%lld\n", j, f, sm[1][0], p[1][0], ans);
		}
		for(i = 1 ; i <= n ; i++) {
			// printf("j=%d\n", (j-1+n)%n);
			s += (lli)a[(j-1+n)%n];
			if(f == 0 && sm[1][0] > s) {
				sm[1][0] = s;
				p[1][0] = (j-1+n)%n;
				// printf("j=%d | f=%d | sm=%lld | p=%d | ans=%lld\n", (j-1+n)%n, f, sm[1][0], p[1][0], ans);
			}
			if(f == 1) {
				stemp += (lli)a[(j-1+n)%n];
				ans = min(ans, s+stemp);
				b[1][(j-1+n)%n] = min(temp, s+stemp);
				temp = b[1][(j-1+n)%n];
				if(sm[1][1] > s) {
					sm[1][1] = s;
					p[1][1] = (j-1+n)%n;
				}
				// printf("j=%d | f=%d | sm=%lld | p=%d | ans=%lld | s+stemp=%lld | bmin=%lld\n", (j-1+n)%n, f, sm[1][1], p[1][1], ans, s+stemp, b[1][(j-1+n)%n]);
			}
			j--;
			if(j < 0)
				j += n;
			j %= n;
			if(j == end){
				ans = min(ans, s);
				b[1][j] = min(temp, s);
				temp = b[1][j];
				stemp = 0LL;
				f = 1;
			}
		}
		sm[1][0] *= 2LL;
		// printf("\n------------------\n");
		// printf("ans=%lld\n", ans);
		// printf("sm=%lld | p=%d | pn=%d | b=%lld | tot=%lld\n", sm[0][0], p[0][0], p[0][0], b[1][p[0][0]], sm[0][0]+b[1][p[0][0]]);
		// printf("sm=%lld | p=%d | pn=%d | b=%lld | tot=%lld\n", sm[1][0], p[1][0], p[1][0], b[0][p[1][0]], sm[1][0]+b[0][p[1][0]]);
		ans = min(ans, sm[0][0]+b[1][p[0][0]]);
		ans = min(ans, sm[1][0]+b[0][p[1][0]]);
		cout << ans << "\n";
		// printf("\n======================\n");
	}
	return 0;
}