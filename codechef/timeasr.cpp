#include <bits/stdc++.h>
#define N 1000
#define PB push_back
using namespace std;
vector < int > valid;
double ang1[N], ang2[N], used[N];
int main(){
	int h, m, t, k;
	double angh, angm, a, err;
	err = 1 / 120.0;
	angh = 0;
	for(int i = 0 ; i < 12 ; i++){
		angm = 0;
		for(int j = 0 ; j < 60 ; j++){
			ang1[k] = abs(angh - angm);
			ang2[k] = 360 - ang1[k];
			k++;
			angh += 0.5;
			angm += 6;
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%lf", &a);
		valid.clear();
		for(int i = 0 ; i < k ; i++){
			if(abs(ang1[i] - a) < err){
				valid.PB(i);
				used[i] = 1;
			}
		}
		for(int i = 0 ; i < k ; i++){
			if((abs(ang2[i] - a) < err) && used[i] == 0)
				valid.PB(i);
		}
		sort(valid.begin(), valid.end());
		for(int i = 0 ; i < valid.size() ; i++){
			used[valid[i]] = 0;
			h = valid[i] / 60;
			valid[i] -= (h*60);
			printf("%02d:%02d\n", h, valid[i]);
		}
	}
	return 0;
}