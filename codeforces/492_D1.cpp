#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 100005
using namespace std;
typedef long long int lli;
int a[N];
vector < pair < lli, int > > mp;
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
	// cout << "b=" << b << " g=" << g << " x=" << x << " y=" << y << endl;
	s = 0;
	j = 0;
	for(int i = 0 ; i < y ; i++){
		s += (lli)x;
		mp.PB(MP(s,1));
	}
	s = 0;
	for(int i = 0 ; i < x ; i++){
		s += (lli)y;
		mp.PB(MP(s,2));
	}
	sort(mp.begin(), mp.end());
	for(int i = 0 ; i < n ; i++){
		t4 = a[i] % b;
		// cout << "t4=" << t4 << endl;
		if(t4 == 0 || t4 == b-1)
			printf("Both\n");
		else{
			if(mp[t4-1].SS == 1)
				printf("Vova\n");
			else
				printf("Vanya\n");
		}
	}
	return 0;
}