#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define gc getchar_unlocked
#else
#define gc getchar
#endif
using namespace std;
inline void scanint(int &x){
	char c;
	x = 0;
	c = gc();
	while(c < '0' or c > '9')
		c = gc();
	while(c >= '0' and c <= '9'){
		x = (x << 3) + (x << 1) + (c - 48);
		c = gc();
	}
}
int main(){
	int x;
	ios::sync_with_stdio(false);
	scanint(x);
	cout << x;
	return 0;
}
