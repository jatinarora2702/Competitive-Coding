#include <bits/stdc++.h>
#define N 1000000
using namespace std;
/*
int getval(int *a, int i) {
	if(a[i] != N)
		return a[i];
	int j = (i+1)/2;
	a[i] = 1 + getval(a,j-1) + getval(a,i-j-1);
	return a[i];
}
*/
int getmax(vector < int >& p) {
	int max = 0;
	for(int i = 0 ; i < p.size() ; i++ ) {
		if(p[max] < p[i])
			max = i;
	}
	return max;
}
int main() {
	int t, d, max, sum, tcnt, min, new_min, vmax, k;
	scanf("%d",&t);
	//a = new int[1000];
	//a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 3; a[4] = 4; a[5] = 4;
	//for(int i = 6 ; i < 1000 ; i++ ) {
	//	a[i] = N;
	//}
	tcnt = 0;
	while(t--) {
		scanf("%d",&d);
		vector < int > p(d);
		for(int i = 0 ; i < d; i++ ) {
			scanf("%d",&p[i]);
		}
		k = 0;
		min = N;
		while(true) {
			max = getmax(p);
			vmax = p[max];
			new_min = k + vmax;
			if(new_min < min)
				min = new_min;
			if(vmax <= 3)
				break;
			p[max] = vmax/2;
			p.push_back(vmax - p[max]);
			k++;
		}
		//sum = getval(a,p[max]-1);
		tcnt++;
		printf("Case #%d: %d\n",tcnt,min);
	}
	return 0;
}