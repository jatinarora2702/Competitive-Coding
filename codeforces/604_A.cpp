#include <bits/stdc++.h>
using namespace std;
int m[10], w[10];
int main() {
	int hs, hu, k, si;
	double s;
	for(int i = 0 ; i < 5 ; i++)
		scanf("%d", &m[i]);
	for(int i = 0 ; i < 5 ; i++)
		scanf("%d", &w[i]);
	scanf("%d%d", &hs, &hu);
	s = 0;
	k = 0;
	for(int i = 0 ; i < 5 ; i++){
		k += 500;
		s += max((3*k)/10.0, ((250-m[i])*k - (50*250*w[i])) / 250.0);
	}
	si = s;
	si += ((100 * hs) - (50 * hu));
	printf("%d", si);
	return 0;
}