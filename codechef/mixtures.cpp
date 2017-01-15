#include <bits/stdc++.h>
#define INF 1e9+7
using namespace std;
int main() {
	int n, *a, **mix, **smk, sum, k, min, val;
	while(scanf("%d", &n) != EOF){
		mix = new int*[n];
		smk = new int*[n];
		for(int i = 0 ; i < n ; i++){
			mix[i] = new int[n];
			smk[i] = new int[n];
			scanf("%d", &mix[i][i]);
			smk[i][i] = 0;
		}
		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; j < n-i ; j++){
				k = j+i;
				mix[j][k] = (mix[j][k-1] + mix[k][k]) % 100;
			}
		}
		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; j < n-i ; j++){
				k = j+i;
				min = INF;
				for(int it = j ; it < k ; it++){
					val = smk[j][it] + smk[it+1][k] + mix[j][it] * mix[it+1][k];
					if(val < min)
						min = val;
				}
				smk[j][k] = min;
			}
		}
		printf("%d\n", smk[0][n-1]);
	}
	return 0;
}