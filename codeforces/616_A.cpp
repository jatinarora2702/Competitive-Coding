#include <bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define N 1000005
using namespace std;
typedef long long int lli;
const int MOD = 1e9+7;
char s1[N], s2[N];
int main(){
	int n, m, f, k1, k2, n1, m1, i1, j1;
	scanf("%s %s", s1, s2);
	n = n1 = 0;
	m = m1 = 0;
	k1 = k2 = 0;
	f = 0;
	for(int i = 0 ; s1[i] != '\0' ; i++){
		n++;
		if(s1[i] != '0' && f == 0){
			k1 = i;
			f = 1;
		}
		if(f == 1)
			n1++;
	}
	if(f == 0)
		k1 = n;
	f = 0;
	for(int i = 0 ; s2[i] != '\0' ; i++){
		m++;
		if(s2[i] != '0' && f == 0){
			k2 = i;
			f = 1;
		}
		if(f == 1)
			m1++;
	}
	if(f == 0)
		k2 = m;
	if(n1 < m1)
		printf("<");
	else if(m1 < n1)
		printf(">");
	else{
		f = 0;
		i1 = k1;
		j1 = k2;
		while(i1 < n){
			if(s1[i1] > s2[j1]){
				f = 1;
				break;
			}
			else if(s1[i1] < s2[j1]){
				f = -1;
				break;
			}
			i1++;
			j1++;
		}
		if(f == -1)
			printf("<");
		else if(f == 1)
			printf(">");
		else
			printf("=");
	}
	return 0;
}