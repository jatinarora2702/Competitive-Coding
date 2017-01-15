#include <bits/stdc++.h>
#define FF first
#define SS second
#define N 100005
using namespace std;
typedef long long int lli;
int a[N];
map < lli, int > mp;
map < lli, int > :: iterator it;
int main() {
	int n, x, y, t1, t2, t3, t4, g, j, b;
	lli l, t, s;
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);
	t1 = max(x, y);
	t2 = min(x, y);
	while(t2 > 0){
		t3 = t1 % t2;
		t1 = t2;
		t2 = t3;
	}
	g = t1;
	b = (x + y) / g;
	x /= g;
	y /= g;
	s = 0;
	for(int i = 0 ; i < y ; i++){
		s += (lli)x;
		mp[s] = 1;
	}
	s = 0;
	for(int i = 0 ; i < x ; i++){
		s += (lli)y;
		mp[s] = 2;
	}
	for(int i = 0 ; i < n ; i++){
		t4 = a[i] % b;
		if(t4 == 0 || t4 == b-1)
			printf("Both\n");
		else{
			j = 1;
			it = mp.begin();
			while(j < t4){
				it++;
				j++;
			}
			if(it->SS == 1)
				printf("Vova\n");
			else
				printf("Vanya\n");
		}
	}
	return 0;
}