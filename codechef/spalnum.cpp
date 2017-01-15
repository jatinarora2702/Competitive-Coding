#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long int lli;
int pal[N];
lli sum[N];
int main(){
	int j, t, l, r, lm;
	j = 0;
	for(int i = 1 ; i < 10 ; i++)
		pal[j++] = i;
	for(int i = 11 ; i < 100 ; i+=11)
		pal[j++] = i;
	int cnt = 1;
	for(int k = 100 ; k < 1000 ; k+=100){
		lm = k + cnt;
		cnt++;
		for(int i = lm ;  i < k+100 ; i+=10)
			pal[j++] = i;
	}
	cnt = 1;
	for(int k = 1000 ; k < 10000 ; k+=1000){
		l = k + cnt;
		cnt++;
		for(int i = l ; i < k+1000 ; i+=110)
			pal[j++] = i;
	}
	cnt = 1;
	for(int l1 = 10000 ; l1 < 100000 ; l1+=10000){
		l = l1 + cnt;
		cnt++;
		for(int l2 = l ; l2 < l+10000 ; l2+=1010){
			for(int i = 0 ; i < 10 ; i++){
				pal[j++] = l2 + i*100;
			}
		}
	}
	// for(int i = 0 ; i < j ; i++)
	// 	printf("%d\n", pal[i]);
	sum[0] = 1;
	for(int i = 0 ; i < j ; i++)
		sum[i] = sum[i-1] + (lli)pal[i];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &l, &r);
		int *lp, *rp, li, ri;
		lp = lower_bound(pal, pal+j, l);
		rp = lower_bound(pal, pal+j, r);
		li = lp - pal;
		ri = rp - pal;
		if(pal[ri] != r)
			ri--;
		lli k1 = sum[ri];
		if(li != 0)
			k1 = k1 - sum[li-1];
		cout << k1 << endl;
	}
	return 0;
}