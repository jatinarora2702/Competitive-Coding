#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
typedef unsigned long long int ulli;
int main(){
	int m, h1, h2, x1, x2, y1, y2, a1, a2, f1, f2, k1, k2, f, j, s, *arr;
	ulli sum1, sum2;
	pair < set < int > :: iterator, bool > r1, r2;
	scanf("%d%d%d%d%d%d%d%d%d", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);
	set <int> s1;
	set <int> s2;
	h1 %= m; h2 %= m;
	x1 %= m; x2 %= m;
	y1 %= m; y2 %= m;
	k1 = k2 = 1;
	f1 = f2 = -1;
	//cout << "m=" << m << " h1=" << h1 << " a1=" << a1 << " x1=" << x1 << " y1=" << y1 << " h2=" << h2 << " a2=" << a2 << " x2=" << x2 << " y2=" << y2 << endl;
	s1.insert(h1);
	s2.insert(h2);
	//cout << "sum1 : " << h1 << endl;
	arr = new int[m];
	arr[0] = h1;
	while(true){
		sum1 = ((ulli)((ulli)x1 * h1) + y1) % m;
		//cout << "sum1 : " << sum1 << endl;
		r1 = s1.insert(sum1);
		if(r1.second == true){
			k1++;
			arr[k1-1] = sum1;
			h1 = sum1;
			if(sum1 == a1)
				f1 = k1-1;
		}
		else{
			for(j = 0 ; j < m ; j++)
				if(arr[j] == sum1)
					break;
			k1 = k1 - j;
			break;
		}
	}
	//cout << f1 << " " << k1 << endl;
	//cout << "sum2 : " << h2 << endl;
	arr[0] = h2;
	while(true){
		sum2 = ((ulli)((ulli)x2 * h2) + y2) % m;
		//cout << "sum2 : " << sum2 << endl;
		r2 = s2.insert(sum2);
		if(r2.second == true){
			k2++;
			arr[k2-1] = sum2;
			h2 = sum2;
			if(sum2 == a2)
				f2 = k2-1;
		}
		else{
			for(j = 0 ; j < m ; j++){
				if(arr[j] == sum2)
					break;
			}
			k2 = k2 - j;
			break;
		}
	}
	//cout << f2 << " " << k2 << endl;
	if(f1 == -1 or f2 == -1)
		printf("-1");
	else{
		f = (f2 - f1);
		s = 0;
		for(j = 0 ; j <= k1 ; j++){
			if(f % k1 == 0)
				break;
			s += k2;
			f += k2;
			f %= k1;
		}
		printf("%d", s+f2);
	}
	return 0;
}