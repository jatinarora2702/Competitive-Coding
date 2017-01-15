#include <bits/stdc++.h>
#define N 100005
using namespace std;
int main(){
	int n, s, buy[N], sell[N], a[1005], kb, ks, k, b[1005], x, m;
	char c;
	scanf("%d%d", &n, &s);
	for(int i = 0 ; i < N; i++){
		buy[i] = 0;
		sell[i] = 0;
	}
	kb = ks = 0;
	for(int i = 0 ; i < n ; i++){
		c = getchar();
		scanf("%c %d %d", &c, &x, &m);
		// cout << "c=" << c << " x=" << x << " m=" << m << endl;
		if(c == 'B'){
			if(buy[x] == 0){
				a[kb] = x;
				kb++;
			}
			buy[x] += m;
		}
		else{
			if(sell[x] == 0){
				b[ks] = x;
				ks++;
			}
			sell[x] += m;
		}
	}
	sort(a, a+kb);
	sort(b, b+ks);
	// for(int i = 0 ; i < kb ; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	k = 0;
	if(s >= ks){
		for(int i = ks-1 ; i >= 0 ; i--)
			printf("S %d %d\n", b[i], sell[b[i]]);	
	}
	else if(s < ks){
		for(int i = s-1 ; i >= 0 ; i--)
			printf("S %d %d\n", b[i], sell[b[i]]);		
	}
	k = 0;
	while(k < s && kb-k-1 >= 0){
		printf("B %d %d\n", a[kb-k-1], buy[a[kb-k-1]]);
		k++;
	}
	return 0;
}