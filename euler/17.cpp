#include <bits/stdc++.h>
using namespace std;

map < int, int > mp;

int getwordcnt(int n) {
	int n1, n2, m, cnt;
	if(n <= 0)
		return 0;
	if(mp.find(n) == mp.end()) {
		n2 = n % 1000;
		n1 = n / 1000;
		cnt = 0;
		if(n1 > 0)
			cnt += getwordcnt(n1) + mp[1000] - 3;
		if(n2 > 0) {
			m = n2;
			n2 = m % 100;
			n1 = m / 100;
			if(n1 > 0)
				cnt += getwordcnt(n1) + mp[100] - 3;
			if(n2 > 0) {
				if(n1 > 0)
					cnt += 3;
				m = n2;
				if(m >= 0 && m <= 20)
					cnt += getwordcnt(m);
				else {
					n1 = m % 10;
					cnt += getwordcnt(n1);
					m -= n1;
					cnt += getwordcnt(m);
				}
			}
		}
		mp[n] = cnt;
	}
	return mp[n];
}

int main() {
	int n, i, s;
	mp[1] = 3;
	mp[2] = 3;
	mp[3] = 5;
	mp[4] = 4;
	mp[5] = 4;
	mp[6] = 3;
	mp[7] = 5;
	mp[8] = 5;
	mp[9] = 4;
	mp[10] = 3;
	mp[11] = 6;
	mp[12] = 6;
	mp[13] = 8;
	mp[14] = 8;
	mp[15] = 7;
	mp[16] = 7;
	mp[17] = 9;
	mp[18] = 8;
	mp[19] = 8;
	mp[20] = 6;
	mp[30] = 6;
	mp[40] = 5;
	mp[50] = 5;
	mp[60] = 5;
	mp[70] = 7;
	mp[80] = 6;
	mp[90] = 6;
	mp[100] = 10;
	mp[1000] = 11;
	scanf("%d", &n);
	s = 0;
	for(i = 1 ; i <= n ; i++) {
		s += getwordcnt(i);
		// printf("i=%d | w=%d\n", i, getwordcnt(i));
	}
	printf("%d\n", s);
	return 0;
}