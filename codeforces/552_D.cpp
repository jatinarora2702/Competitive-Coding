#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
set < double > st;
typedef unsigned long long int ulli;
int collinear(int x1, int y1, int x2, int y2, int x3, int y3, int kk) {
	pair < set < int > :: iterator, bool > p;
  bool temp =  ((y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2));
  if(temp == true){
  	p = st.insert((y2 - y1) / (float)(x2 - x1));
  if(p.second == false)
  	return 2;
  else 
  	return 1;
}
return 0;
  }
int main(){
	int n, x, y, cnt;
	double sp;
	ulli k ,tot;
	scanf("%d", &n);
	vector < pair < int, int > > vp(n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &vp[i].first, &vp[i].second);
	}
	k = tot = 0;
	int kk = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			cnt = 2;
			kk++;
			for(int k1 = 0 ; k1 < n ; k1++){
				if(k1 == i or k1 == j)
					continue;
				int f = collinear(vp[i].first, vp[i].second, vp[j].first, vp[j].second, vp[k1].first, vp[k1].second, kk);
				if(f == true)
					cnt++;
			}
			if(cnt > 2)
				k += (((ulli)cnt * (ulli)(cnt-1) * (ulli)(cnt-2)) / 6);
		}
	}
	
	cout << k << endl;
	tot = (((ulli)n * (ulli)(n-1) * (ulli)(n-2)) / 6);
	cout << tot << endl;
	cout << tot - k;
	return 0;
}