#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int a, b, diff, kd, fd;
	float xs, xd, s1, s2;
	scanf("%d%d", &a, &b);
	lli sum, ks, fs;
	diff = a - b;
	if(diff < 0)
		printf("-1");
	else if(diff == 0)
		printf("%d", b);
	else{
		sum = (lli)a + (lli)b;
		ks = (lli)sum / (lli)(2*b);
		kd = diff / (2*b);
		ks = 2 * ks;
		kd = 2 * kd;
		if(ks != 0)
			fs = (lli)sum / (lli)ks;
		else
			fs = 0;
		if(fd != 0)
			fd = diff / kd;
		else
			fd = 0;
		sum -= (lli)(fs * (lli)ks);
		diff -= (fd * kd);
		xs = (float)sum / (float)ks;
		xd = (float)diff / (float)kd;
		s1 = xs + (float)fs;
		s2 = xd + (float)fd;
		printf("%0.12f", min(s1, s2));
	}
	return 0;
}