#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define N 200005
using namespace std;
char a[N], b[N];
pair < int, int > p[N], q[N], *ptr;
map < pair < int, int >, int > mup, mdown;
int up[30], down[30], posn[N];
int main(){
	int n, cnt, pos, j, f, k, t;
	scanf("%d %s %s", &n, a, b);
	cnt = 0;
	f = 0;
	j = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] != b[i]){
			p[j] = MP(a[i], b[i]);
			q[j] = MP(b[i], a[i]);
			posn[j] = i;
			j++;
			up[a[i]-'a'] = 1;
			down[b[i]-'a'] = 1;
			cnt++;
		}
	}
	sort(q, q+j);
	for(int i = 0 ; i < j ; i++){
		ptr = lower_bound(q, q+j, p[i]);
		t = ptr - q;
		if(t >= 0 && t < j && q[t] == p[i]){
			k = i;
			f = 2;
			break;
		}
	}
	// printf("cnt=%d\n", cnt);
	if(f == 2){
		printf("%d\n", cnt-2);
		// for(int i = 0 ; i < j ; i++){
		// 	if(p[k].FF == p[i].FF && p[k].SS == p[i].SS){
		// 		printf("%d ", posn[i]);
		// 		break;
		// 	}
		// }
		printf("%d ", posn[k]+1);
		for(int i = 0 ; i < j ; i++){
			if(p[k].SS == p[i].FF && p[k].FF == p[i].SS){
				printf("%d ", posn[i]+1);
				break;
			}
		}
	}
	else{
		// for(int i =0  ; i < 26 ; i++)
		// 	printf("%d ", up[i]);
		// printf("\n");
		// for(int i = 0 ; i < 26 ; i++)
		// 	printf("%d ", down[i]);
		// printf("\n");
		for(int i = 0 ; i < 26 ; i++){
			if(up[i] == 1 && down[i] == 1){
				f = 1;
				pos = i;
				break;
			}
		}
		if(f == 1){
			printf("%d\n", cnt-1);
			// printf("ll : %c\n", pos+'a');
			for(int i = 0 ; i < j ; i++){
				if(p[i].FF == pos+'a'){
					printf("%d ", posn[i]+1);
					break;
				}
			}
			for(int i = 0 ; i < j ; i++){
				if(p[i].SS == pos+'a'){
					printf("%d\n", posn[i]+1);
					break;
				}
			}
		}
		else{
			printf("%d\n-1 -1\n", cnt);
		}
	}
	return 0;
}