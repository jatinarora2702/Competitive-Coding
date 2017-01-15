#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, t, flag, f, v, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		m = 0;
		flag = 0;
		f = 1;
		for(int i = 0 ; i < 32 ; i++){
			v = 1 << i;
			if(v > n)
				break;
			k = n & v;
			if(flag == 1 && k != 0){
				f = 0;
				break;
			}
			// cout << k << " ";
			if(k == v){
				m += v;
			}
			else if(k == 0){
				if(flag == 0){
					m -= (v / 2);
					flag = 1;
				}
			}
		}
		// cout << endl;
		if(f == 1){
			if(flag == 0)
				m -= (v / 2);
			printf("%d\n", m);
		}
		else
			printf("-1\n");
	}
	return 0;
}