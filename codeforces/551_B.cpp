#include <iostream>
#include <stdio.h>
#define N 100001
#define INF 1000000007
using namespace std;
int main(){
	char a[N], b[N], c[N], s[N];
	int dpa[26], dpb[26], dpc[26], dp[26], min, k , cnt, max, d[2][2];
	scanf("%s%s%s", a, b, c);
	for(int i = 0 ; a[i] != '\0' ; i++)
		dpa[a[i]-'a']++;
	for(int i = 0 ; b[i] != '\0' ; i++)
		dpb[b[i]-'a']++;
	for(int i = 0 ; c[i] != '\0' ; i++)
		dpc[c[i]-'a']++;
	cnt = 0;
	min = INF;
	for(int i = 0 ; i < 26 ; i++){
		if(dpb[i] != 0){
			k = dpa[i] / dpb[i];
			if(k < min)
				min = k;
		}
	}
	for(int i = 0 ; i < 26 ; i++){
		dp[i] = dpa[i]-min*dpb[i];
	}
	cnt += min;
	d[0][0] = min;
	min = INF;
	for(int i = 0 ; i < 26 ; i++){
		if(dpc[i] != 0){
			k = dp[i] / dpc[i];
			if(k < min)
				min = k;
		}
	}
	cnt += min;
	d[0][1] = min;
	max = cnt;
	//cout << cnt << " " << max << endl;
	//---------------------------------//
	cnt = 0;
	min = INF;
	for(int i = 0 ; i < 26 ; i++){
		if(dpc[i] != 0){
			k = dpa[i] / dpc[i];
			if(k < min)
				min = k;
		}
	}
	for(int i = 0 ; i < 26 ; i++){
		dp[i] = dpa[i]-min*dpc[i];
	}
	cnt += min;
	d[1][1] = min;
	min = INF;
	for(int i = 0 ; i < 26 ; i++){
		if(dpb[i] != 0){
			k = dp[i] / dpb[i];
			if(k < min)
				min = k;
		}
	}
	cnt += min;
	d[1][0] = min;
	/*for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < 2 ; j++)
			printf("%d", d[i][j]);
		printf("\n");
	}*/
	//cout << cnt << endl;
	if(max > cnt)
		k = 0;
	else
		k = 1;
	for(int i = 0 ; i < d[k][0] ; i++)
		printf("%s", b);
	for(int i = 0 ; i < d[k][1] ; i++)
		printf("%s", c);
	for(int i = 0 ; i < 26 ; i++){
		dpa[i] -= (d[k][0]*dpb[i] + d[k][1]*dpc[i]);
		if(dpa[i] != 0){
			for(int j = 0 ; j < dpa[i] ; j++)
				printf("%c", i+'a');
		}
	}
	return 0;
}