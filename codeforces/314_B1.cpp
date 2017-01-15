#include <bits/stdc++.h>
#define N 105
using namespace std;
char a[N], c[N];
int main(){
	int b, d, m, n ,cnta, cntc, cntq, val;
	scanf("%d%d%s%s", &b, &d, a, c);
	int i, j, k, f;
	n = strlen(a);
	m = strlen(c);
	cnta = 0;
	cntc = 0;
	cntq = 0;
	i = j = k = f = 0;
	while(cnta < b){
		if(f == 1 && i == 0 && k == 0)
			break;
		if(a[i] == c[j]){
			i++;
			j++;
			k++;
			if(i == n){
				i = 0;
				cnta++;
			}
			if(j == m){
				j = 0;
				cntc++;
				if(cntc == d){
					k = 0;
					cntc = 0;
					cntq++;
					f = 1;
				}
			}
		}
		else{
			i++;
			if(i == n){
				i = 0;
				cnta++;
			}
		}
	}
	val = (cntq * b) / cnta;
	cout << val << endl;
	val += ((cntc * b) / (cnta * d));
	printf("%d", val);
	return 0;
}