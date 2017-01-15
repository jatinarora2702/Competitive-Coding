#include <bits/stdc++.h>
#define N 60
using namespace std;

char a[N][N], b[N];
int main() {
	int t, n, k, f, cnt, win, h, i, j, k1;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%d%d", &n, &k);
		for(i = 0 ; i < n ; i++) {
			scanf("%s", a[i]);
		}
		// printf("\n------------\n");

		// for(i = 0 ; i < n ; i++) {
		// 	printf("%s\n", a[i]);
		// }
		for(i = 0 ; i < n ; i++)
			b[i] = n-1;
		
		for(j = n-1 ; j >= 0 ; j--) {
			for(i = 0 ; i < n ; i++) {
				if(a[i][j] != '.') {
					a[i][b[i]] = a[i][j];
					if(j != b[i])
						a[i][j] = '.';
					b[i]--;
				}
			}
		}		
		// printf("\n------------\n");
		// for(i = 0 ; i < n ; i++) {
		// 	printf("%s\n", a[i]);
		// }
		// printf("\n-----------\n");
		win = 0;
		for(i = 0 ; i < n ; i++) {
			cnt = 0;
			f = 0;
			for(j = 0 ; j < n ; j++) {
				if(a[i][j] != '.') {
					if(a[i][j] == 'R') {
						if(f != 1) {
							f = 1;
							cnt = 0;
						}
						cnt++;
					}
					else {
						if(f != 2) {
							f = 2;
							cnt = 0;
						}
						cnt++;	
					}
					// printf("i=%d | j=%d | f=%d | cnt=%d\n", i, j, f, cnt);
					if(cnt == k && f != 0) {
						if(win != 0 && win != f)
							win = 3;
						else
							win = f;
					}
				}
				else {
					f = 0;
					cnt = 0;
				}
			}
		}
		// printf("1. win = %d\n", win);
		for(j = 0 ; j < n ; j++) {
			cnt = 0;
			f = 0;
			for(i = 0 ; i < n ; i++) {
				if(a[i][j] != '.') {
					if(a[i][j] == 'R') {
						if(f != 1) {
							f = 1;
							cnt = 0;
						}
						cnt++;
					}
					else {
						if(f != 2) {
							f = 2;
							cnt = 0;
						}
						cnt++;	
					}
					if(cnt == k && f != 0) {
						if(win != 0 && win != f)
							win = 3;
						else
							win = f;
					}
				}
				else {
					f = 0;
					cnt = 0;
				}
			}
		}
		// printf("2. win = %d\n", win);
		for(k1 = 0 ; k1 < n ; k1++) {
			i = k1;
			cnt = 0;
			f = 0;
			for(j = 0 ; j < n ; j++) {
				if(a[i][j] != '.') {
					if(a[i][j] == 'R') {
						if(f != 1) {
							f = 1;
							cnt = 0;
						}
						cnt++;
					}
					else {
						if(f != 2) {
							f = 2;
							cnt = 0;
						}
						cnt++;	
					}
					if(cnt == k && f != 0) {
						if(win != 0 && win != f)
							win = 3;
						else
							win = f;
					}
				}
				else {
					f = 0;
					cnt = 0;
				}
				i--;
				if(i < 0)
					break;
			}
		}
		// printf("3. win = %d\n", win);
		for(k1 = 1 ; k1 < n ; k1++) {
			j = k1;
			cnt = 0;
			f = 0;
			for(i = n-1 ; i >= 0 ; i--) {
				if(a[i][j] != '.') {
					if(a[i][j] == 'R') {
						if(f != 1) {
							f = 1;
							cnt = 0;
						}
						cnt++;
					}
					else {
						if(f != 2) {
							f = 2;
							cnt = 0;
						}
						cnt++;	
					}
					if(cnt == k && f != 0) {
						if(win != 0 && win != f)
							win = 3;
						else
							win = f;
					}
				}
				else {
					f = 0;
					cnt = 0;
				}
				j++;
				if(j == n)
					break;
			}
		}
		// printf("4. win = %d\n", win);
		for(k1 = 0 ; k1 < n ; k1++) {
			j = k1;
			cnt = 0;
			f = 0;
			for(i = n-1 ; i >= 0 ; i--) {
				if(a[i][j] != '.') {
					if(a[i][j] == 'R') {
						if(f != 1) {
							f = 1;
							cnt = 0;
						}
						cnt++;
					}
					else {
						if(f != 2) {
							f = 2;
							cnt = 0;
						}
						cnt++;	
					}
					if(cnt == k && f != 0) {
						if(win != 0 && win != f)
							win = 3;
						else
							win = f;
					}
				}
				else {
					f = 0;
					cnt = 0;
				}
				j--;
				if(j < 0)
					break;
			}
		}
		// printf("5. win = %d\n", win);
		for(k1 = 1 ; k1 < n ; k1++) {
			j = k1;
			cnt = 0;
			f = 0;
			for(i = 0 ; i <= n ; i++) {
				if(a[i][j] != '.') {
					if(a[i][j] == 'R') {
						if(f != 1) {
							f = 1;
							cnt = 0;
						}
						cnt++;
					}
					else {
						if(f != 2) {
							f = 2;
							cnt = 0;
						}
						cnt++;	
					}
					if(cnt == k && f != 0) {
						if(win != 0 && win != f)
							win = 3;
						else
							win = f;
					}
				}
				else {
					f = 0;
					cnt = 0;
				}
				j++;
				if(j == n)
					break;
			}
		}
		// printf("6. win = %d\n", win);
		printf("Case #%d: ", h);
		switch(win) {
			case 0: printf("Neither\n"); break;
			case 1: printf("Red\n"); break;
			case 2: printf("Blue\n"); break;
			case 3: printf("Both\n"); break;
		}
	}
	return 0;
}