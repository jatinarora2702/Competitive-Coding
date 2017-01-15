#include <bits/stdc++.h>
#define N 105
using namespace std;
int d[10], b[N];
int main() {
	int t, i, j, k, s;
	scanf("%d", &t);
	while(t--) {
		s = 0;
		k = 0;
		for(i = 0 ; i < 9 ; i++) {
			scanf("%d", &d[i]);
			s += (i+1)*d[i];
			for(j = 0 ; j < d[i] ; j++) {
				b[k++] = (i+1);
			}
		}
		n = k;
		k = 0;
		while(1) {
			temp = s;
			temp -= (11 * k);
			if(temp <= 0)
				break;
			if(temp % 2 == 0) {
				temp1 = temp / 2;
				
			}
			k++;
		}

	}
}