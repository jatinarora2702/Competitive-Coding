#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
double min(double a, double b, double c){
	if(a < b){
		if(a < c)
			return a;
		else
			return c;
	}
	else{
		if(b < c)
			return b;
		else
			return c;
	}
}
int main() {
	int n, w, *a;
	double tmp1, tmp2, tmp3, x, maxw;
	scanf("%d%d", &n, &w);
	a = new int[2 * n];
	for(int i = 0 ; i < 2 * n ; i++)
		scanf("%d", &a[i]);
	sort(a, a+2*n);
	tmp1 = w / (double)(3 * n);
	// cout << maxm << endl;
	tmp2 = a[n] / 2.0;
	tmp3 = (double)a[0];
	// cout << tmp1 << " " << tmp2 << " " << tmp3 << endl;
	x = min(tmp1, tmp2, tmp3);
	maxw = (double)(3 * n) * x;
	printf("%lf", maxw);
	return 0;
}