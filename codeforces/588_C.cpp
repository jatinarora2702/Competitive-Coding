#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int a[N], w[N];
int main() {
	int n, k, cnt, v;
	scanf("%d", &n);
	for(int i = 0 ; i < N ; i++)
		w[i] = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		w[a[i]]++;
	}
	cnt = 0;
	for(int i = 0 ; i < N ; i++){
		if(w[i] != 0){
			v = w[i];
			k = i;
			w[i] = 0;
			while(v > 0){
				if(v % 2 == 1){
					if(k >= N)
						cnt++;
					else
						w[k]++;
				}
				v /= 2;
				k++;
			}
		}
	}
	// cout << "yo\n";
	// for(int i = 0 ; i < 6 ; i++)
	// 	cout << w[i] << endl;
	for(int i = 0 ; i < N ; i++){
		if(w[i] != 0)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}