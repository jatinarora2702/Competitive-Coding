#include <bits/stdc++.h>
#define N 100005
#define INF 100000
using namespace std;
int a[N], p[N];
int main(){
	int n, s, pr;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &a[i], &p[i]);
	}
	pr = INF;
	s = 0;
	for(int i = 0 ; i < n ; i++){
		if(p[i] < pr){
			pr = p[i];
		}
		s += pr * a[i];
	}
	printf("%d\n", s);
	return 0;
}