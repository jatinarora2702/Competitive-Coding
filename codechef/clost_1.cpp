#include <bits/stdc++.h>
#define ff first
#define ss second
#define K 35
#define N 2005
using namespace std;
bool cmp(pair < int, int > p1, pair < int, int > p2){
	return (p1.ss-p1.ff) < (p2.ss-p2.ff);
}
int main(){
	int t, n, k, x, y, f;
	pair < int, int > p[K];
	char s[N];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 0 ; i < k ; i++){
			scanf("%d%d", &x, &y);
			p[i] = make_pair(x, y);
		}
		for(int i = 0 ; i < n ; i++)
			s[i] = '.';
		sort(p, p+k, cmp);
		// cout << endl;
		// for(int i = 0 ; i < k ; i++)
		// 	cout << p[i].ff << " " << p[i].ss << " pdone\n";
		for(int i = 0 ; i < k ; i++){
			f = 0;
			for(int j = p[i].ff ; j <= p[i].ss ; j++){
				if(s[j] == '.'){
					if(f == 0){
						s[j] = '(';
						f = 1;
					}
					else{
						s[j] = ')';
						f = 0;
					}
				}
			}
		}
		// s[n] = '\0';
		// printf("s=%s\n", s);
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '.')
				s[i] = '(';
		}
		s[n] = '\0';
		printf("%s\n", s);
	}
	return 0;
}