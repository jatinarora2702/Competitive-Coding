#include <iostream>
#include <cstdio>
#include <cstring>
#define N 101
using namespace std;
typedef long long int lli;
char a[N], c[N];
int main(){
	int b, d, m, n ,cnt, cnta, cntc, cntq, cntac, init;
	lli val, temp, val1;
	scanf("%d%d%s%s", &b, &d, a, c);
	int i, j, k, f;
	for(n = 0 ; a[n] != '\0' ; n++);
	// cout << n << " " << strlen(a) << endl;
	for(m = 0 ; c[m] != '\0' ; m++);
	// cout << m << " " << strlen(c) << endl;
	cnta = cntc = cntq = 0;
	i = j = k = f = 0;
	init = 0;
	while(cnta < b){
		if(i == 0 && j == 0 && f == 1)
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
				if(init == 0){
					cntac = cnta;
					init = 1;
				}
				if(cntc == d){
					cntc = 0;
					k = 0;
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
	// cout << cnta << " " << cntc << " " << cntq << endl;
	// val = (cntq * b) / cnta;
	// cout << val << endl;
	// val += ((cntc * b) / (cnta * d));
	// cout << "val=" << val << endl;
	// cout << cntac << endl;
	// if(cntac == 0){
	// 	printf("0");
	// 	return 0;
	// }
	cnt = b / cnta;
	temp = (lli)b - (lli)cnt * (lli)cnta;
	val = ((lli)cntq * (lli)cnt);
	val1 = ((lli)cntc * (lli)cnt);
	// cout << ((lli)cntq * (lli)cnt) << " ";
	// cout << (((lli)cntc * (lli)cnt) + temp) / (lli)d << endl;
	cnta = cntc = cntq = 0;
	i = j = k = f = 0;
	init = 0;
	while(cnta < temp){
		if(a[i] == c[j]){
			i++;
			j++;
			if(i == n){
				i = 0;
				cnta++;
			}
			if(j == m){
				j = 0;
				cntc++;
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
	val += (val1 + (lli)cntc) / (lli)d;
	cout << val;
	// printf("%d", val);
	return 0;
}