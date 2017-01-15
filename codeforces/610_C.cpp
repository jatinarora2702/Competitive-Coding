#include <bits/stdc++.h>
#define N 1200
using namespace std;
char l1[N][N], l2[N][N];
int main() {
	int k, f, cnt, ncnt, l, m;
	scanf("%d", &k);
	if(k == 0){
		printf("+\n");
		return 0;
	}
	f = 0;
	cnt = 2;
	l1[0][0] = '+';
	l1[1][0] = '+';
	l1[0][1] = '+';
	l1[1][1] = '*';
	for(int i = 2 ; i <= k ; i++){
		ncnt = cnt * 2;
		if(f == 0){
			f ^= 1;
			l = 0;
			for(int j = 0 ; j < cnt ; j++){
				m = 0;
				for(int k1 = 0 ; k1 < cnt ; k1++){
					l2[l][m] = l1[j][k1];
					m++;
				}
				for(int k1 = 0 ; k1 < cnt ; k1++){
					l2[l][m] = l1[j][k1];
					m++;
				}
				m = 0;
				l++;
				for(int k1 = 0 ; k1 < cnt ; k1++){
					l2[l][m] = l1[j][k1];
					m++;
				}
				for(int k1 = 0 ; k1 < cnt ; k1++){
					l2[l][m] = (l1[j][k1] == '+') ? '*' : '+';
					m++;
				}
				l++;
			}
			cnt = ncnt;
		}
		else{
			if(f == 1){
				f ^= 1;
				l = 0;
				for(int j = 0 ; j < cnt ; j++){
					m = 0;
					for(int k1 = 0 ; k1 < cnt ; k1++){
						l1[l][m] = l2[j][k1];
						m++;
					}
					for(int k1 = 0 ; k1 < cnt ; k1++){
						l1[l][m] = l2[j][k1];
						m++;
					}
					m = 0;
					l++;
					for(int k1 = 0 ; k1 < cnt ; k1++){
						l1[l][m] = l2[j][k1];
						m++;
					}
					for(int k1 = 0 ; k1 < cnt ; k1++){
						l1[l][m] = (l2[j][k1] == '+') ? '*' : '+';
						m++;
					}
					l++;
				}
				cnt = ncnt;
			}
		}
	}
	if(f == 0){
		for(int i = 0 ; i < cnt ; i++){
			for(int j = 0 ; j < cnt ; j++){
				printf("%c", l1[i][j]);
			}
			printf("\n");
		}
	}
	else{
		for(int i = 0 ; i < cnt ; i++){
			for(int j = 0 ; j < cnt ; j++){
				printf("%c", l2[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}