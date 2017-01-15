#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, smax, cnt, k, kmax, tcnt;
	char *s;
	scanf("%d",&t);
	tcnt = 0;
	while(t--) {
		scanf("%d",&smax);
		s = new char[smax+2];
		scanf("%s",s);
		k = 0;
		cnt = 0;
		kmax = 0;
		//cout << "smax = " << smax << endl;
		while(k <= smax) {
			//cout << "kmax = " << kmax << " k = " << k  << " s[k] = " << s[k] << ":";
			if(k == kmax+1){
				cnt++;
				kmax = kmax + (s[k] - '0');
				kmax++;
				k++;
				//cout << "in" << endl;
				continue;
			}
			kmax = kmax + (s[k] - '0');
			k++;
			//cout << "out" << endl;
		}
		tcnt++;
		printf("Case #%d: %d\n",tcnt,cnt);
	}
	return 0;
}