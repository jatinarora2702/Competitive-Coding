#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long int lli;
int main(){
	lli n, m, *a, t, tmax, flag, f, l, mid, pos, k;
	cin >> n >> m;
	a = new lli[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	tmax = n;
	for(int i = 0 ; i < n ; i++)
		tmax += a[i];
	//cout << tmax << endl;
	f = 0; l = tmax;
	/*for(int i = 1 ; i < n ; i++)
		a[i] += a[i-1];*/
	while(f <= l){
		flag = 0;
		//cout << f << " " << l << endl;
		k = n-1;
		while(a[k] == 0)
			k--;
		pos = a[k];
		mid = (f + l) / 2;
		//cout << "mid=" << mid << endl;
		for(int i = 0 ; i < m ; i++){
			t = k+1;
			//cout << "t=" << t << " i=" << i << " k=" << k << endl;
			while(true){
				if(t+pos <= mid){
					t += pos;
					k--;
					if(k >= 0)
						pos = a[k];
					else{
						flag = 1;
						break;
					}
				}
				else{
					//cout << "a[k]=" << a[k] << " pos=" << pos << endl;
					pos = pos-(mid-t);
					break;
				}
			}
			if(flag == 1)
				break;
		}
		//cout << "k=" << k << endl;
		if(flag == 1)
			l = mid-1;
		else
			f = mid+1;
	}
	if(flag == 0)
		mid++;
	cout << mid;
	return 0;
}