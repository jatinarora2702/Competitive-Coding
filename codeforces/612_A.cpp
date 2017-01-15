#include <bits/stdc++.h>
#define N 105
using namespace std;
char s[N];
int main(){
	int n, p, q, k1, k2, f, i, j, it, cnt, n1;
	scanf("%d%d%d%s", &n, &p, &q, s);
	f = 0;
	for(int i = 0 ; i <= (n/p) ; i++){
		n1 = n - p * i;
		if(n1 % q == 0){
			j = n1 / q;
			// cout << "i=" << i << " j=" << j << endl;
			printf("%d\n", i+j);
			it = 0;
			cnt = 0;
			while(cnt < i){
				for(int k = 0 ; k < p ; k++)
					printf("%c", s[it++]);
				printf("\n");
				cnt++;
			}
			cnt = 0;
			while(cnt < j){
				for(int k = 0 ; k < q ; k++)
					printf("%c", s[it++]);
				printf("\n");
				cnt++;
			}
			f = 1;
			break;
		}
	}
	if(f == 0){
		for(int i = 0 ; i <= (n/q) ; i++){
			n1 = n - q * i;
			if(n1 % p == 0){
				j = n1 / p;
				printf("%d\n", i+j);
				it = 0;
				cnt = 0;
				while(cnt < i){
					for(int k = 0 ; k < q ; k++)
						printf("%c", s[it++]);
					printf("\n");
					cnt++;
				}
				cnt = 0;
				while(cnt < j){
					for(int k = 0 ; k < p ; k++)
						printf("%c", s[it++]);
					printf("\n");
					cnt++;
				}
				f = 1;
				break;
			}
		}	
	}
	if(f == 0)
		printf("-1");
	return 0;
}