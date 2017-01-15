#include <bits/stdc++.h>
#define N 505
using namespace std;
typedef long long int lli;
int dp1[N][N], dp2[N][N];
char a[N][N];
int main(){
	int h, w, q, cnt, r1, r2, c1, c2;
	scanf("%d%d", &h, &w);
	for(int i = 0 ; i < h ; i++){
		scanf(" %s", a[i]);
	}
	// printf("print:\n");
	// for(int i = 0 ; i < h ; i++){
	// 	cout << a[i] << endl;
	// }
	for(int i = 0 ; i < w ; i++){
		dp1[0][i] = 0;
		cnt = 0;
		if(a[0][i] == '.')
			cnt++;
		for(int j = 1 ; j < h ; j++){
			if(a[j][i] == '.'){
				cnt++;
			}
			else if(a[j][i] == '#')
				cnt = 0;
			dp1[j][i] = dp1[j-1][i];
			if(cnt > 1)
				dp1[j][i]++;
		}
		// cout << "rr: ";
		// for(int j = 0  ; j < h ; j++){
		// 	cout << dp1[j][i] << " ";
		// }
		// cout << endl;
	}
	for(int i = 0 ; i < w-1 ; i++){
		cnt = 0;
		for(int j = 0 ; j < h ; j++){
			if(a[j][i] == '.' && a[j][i+1] == '.')
				cnt++;
			dp2[j][i] = cnt;
		}
	}
	// printf("dp1:\n");
	// for(int j = 0 ; j < h ; j++){
	// 	for(int i = 0 ; i < w ; i++){
	// 		cout << dp1[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }
	// printf("dp2:\n");
	// for(int j = 0 ; j < h ; j++){
	// 	for(int i = 0 ; i < w ; i++){
	// 		cout << dp2[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }
	scanf("%d", &q);
	for(int i = 0 ; i < q ; i++){
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		cnt = 0;
		for(int j = c1 ; j < c2 ; j++){
			// cout << "1 : " << dp1[r2][j] - dp1[r1][j] << endl;
			// cout << "2 : " << dp2[r2][j] - dp2[r1][j] << endl;
			cnt += dp1[r2][j];
			cnt -= dp1[r1][j];
			cnt += dp2[r2][j];
			if(r1 > 0)
				cnt -= dp2[r1-1][j];
		}
		// cout << "1 : " << dp1[r2][c2] - dp1[r1][c2] << endl;
		cnt += dp1[r2][c2];
		cnt -= dp1[r1][c2];
		printf("%d\n", cnt);
	}
	return 0;
}