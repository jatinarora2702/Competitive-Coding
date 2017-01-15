#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long int lli;
int a1[N], a2[N];
int main(){
	int n, kmin, lst, k1, k2, win, j, x;
	lli s1, s2;
	scanf("%d", &n);
	s1 = s2 = 0;
	k1 = k2 = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		if(x > 0){
			s1 += (lli)x;
			a1[k1++] = x;
		}
		else{
			s2 += (lli)(-x);
			a2[k2++] = (-x);
		}
	}
	win = 0;
	if(s1 == s2){
		if(x > 0)
			lst = 1;
		else
			lst = 2;
		j = 0;
		kmin = min(k1, k2);
		while(j < kmin){
			if(a1[j] > a2[j]){
				win = 1;
				break;
			}
			else if(a1[j] < a2[j]){
				win = 2;
				break;
			}
			j++;
		}
		if(win == 0 && k1 != k2){
			if(k1 > k2)
				win = 1;
			else
				win = 2;
		}
		else if(win == 0 && k1 == k2)
			win = lst;	
	}
	else{
		if(s1 > s2)
			win = 1;
		else
			win = 2;
	}
	if(win == 1)
		printf("first");
	else
		printf("second");
	return 0;
}