#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
using namespace std;
pair < int, int > p[6];
pair < int, int > q[3];
pair < int, int > temp;
int a[6];
char s[3];
int main(){
	char tempc;
	int x1, x2, x3, y1, y2, y3, l, k, f;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	p[0] = MP(x1, y1);
	p[1] = MP(y1, x1);
	p[2] = MP(x2, y2);
	p[3] = MP(y2, x2);
	p[4] = MP(x3, y3);
	p[5] = MP(y3, x3);
	f = 0;
	for(int i = 0 ; i < (1 << 6) ; i++){
		k = __builtin_popcount(i);
		if(k == 3){
			for(int j = 0 ; j < 6 ; j++){
				if(i & (1 << j)){
					a[j] = 1;
				}
				else
					a[j] = 0;
			}
			if(a[0] ^ a[1] == 0)
				continue;
			if(a[2] ^ a[3] == 0)
				continue;
			if(a[4] ^ a[5] == 0)
				continue;
			l = 0;
			for(int j = 0 ; j < 6 ; j++){
				if(a[j] == 1)
					q[l++] = p[j];
			}
			if((q[0].ff == q[1].ff) && (q[1].ff == q[2].ff)){
				l = q[0].ss + q[1].ss + q[2].ss;
				if(q[0].ff == l){
					f = 1;
					printf("%d\n", l);
					for(int j = 0 ; j < q[0].ss ; j++){
						for(int m = 0 ; m < l ; m++)
							printf("A");
						printf("\n");
					}
					for(int j = 0 ; j < q[1].ss ; j++){
						for(int m = 0 ; m < l ; m++)
							printf("B");
						printf("\n");
					}
					for(int j = 0 ; j < q[2].ss ; j++){
						for(int m = 0 ; m < l ; m++)
							printf("C");
						printf("\n");
					}
					break;
				}
			}
			else{
				s[0] = 'A';
				s[1] = 'B';
				s[2] = 'C';
				for(int j = 0 ; j < 3 ; j++){
					if((q[0].ff == q[1].ff + q[2].ff) && (q[0].ff == q[0].ss + q[1].ss) && (q[1].ss == q[2].ss)) {
						printf("%d\n", q[0].ff);
						f = 1;
						for(int m = 0 ; m < q[0].ss ; m++){
							for(int m1 = 0 ; m1 < q[0].ff ; m1++)
								printf("%c", s[0]);
							printf("\n");
						}
						for(int m = 0 ; m < q[1].ss ; m++){
							for(int m1 = 0 ; m1 < q[1].ff ; m1++)
								printf("%c", s[1]);
							for(int m2 = 0 ; m2 < q[2].ff ; m2++)
								printf("%c", s[2]);
							printf("\n");
						}
						break;
					}
					temp = q[0];
					q[0] = q[1];
					q[1] = q[2];
					q[2] = temp;
					tempc = s[0];
					s[0] = s[1];
					s[1] = s[2];
					s[2] = tempc;
				}
				if(f == 1)
					break;
				tempc = s[1];
				s[1] = s[2];
				s[2] = tempc;
				temp = q[1];
				q[1] = q[2];
				q[2] = temp;
				for(int j = 0 ; j < 3 ; j++){
					if((q[0].ff == q[1].ff + q[2].ff) && (q[0].ff == q[0].ss + q[1].ss) && (q[1].ss == q[2].ss)) {
						printf("%d\n", q[0].ff);
						f = 1;
						for(int m = 0 ; m < q[0].ss ; m++){
							for(int m1 = 0 ; m1 < q[0].ff ; m1++)
								printf("%c", s[0]);
							printf("\n");
						}
						for(int m = 0 ; m < q[1].ss ; m++){
							for(int m1 = 0 ; m1 < q[1].ff ; m1++)
								printf("%c", s[1]);
							for(int m2 = 0 ; m2 < q[1].ss ; m2++)
								printf("%c", s[2]);
							printf("\n");
						}
						break;
					}
					temp = q[0];
					q[0] = q[1];
					q[1] = q[2];
					q[2] = temp;
					tempc = s[0];
					s[0] = s[1];
					s[1] = s[2];
					s[2] = tempc;
				}
				if(f == 1)
					break;
			}
		}
	}
	if(f == 0)
		printf("-1");
	return 0;
}