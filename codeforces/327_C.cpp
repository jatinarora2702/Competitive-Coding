#include <iostream>
#include <cstdio>
#define N 100005
#define M 1000000007
using namespace std;
typedef long long int lli;
int pows[31];
inline int power(int n){
	lli lt3;
	int rem = 1;
	while(n > 29){
		lt3 = (lli)pows[29] * rem;
		rem = lt3 % M;
		n -= 29;
	}
	lt3 = (lli)pows[n] * rem;
	rem = lt3 % M;
	return rem;
}
int main() {
	char a[N];
	int n, k, t1, t2, t3, p, rem;
	lli lt1, lt2;
	scanf("%s%d", a, &k);
	for(n = 0 ; a[n] != '\0' ; n++);
	pows[0] = 1;
	for(int i = 1 ; i < 30 ; i++)
		pows[i] = 2 * pows[i-1];
	rem = 0;
	for(int i = n ; i >= 0 ; i--){
		if(a[i] == '5' || a[i] == '0'){
			t1 = power(i);
			lt1 = (lli)rem + t1;
			rem = lt1 % M;
		}
	}
	cout << "rem=" << rem << endl;
	lt1 = (lli)n * k;
	cout << "lt1_o:" << lt1 << endl;
	t2 = lt1 % 500000003;
	t1 = power(t2);
	lt1 = (lli)rem;
	if(t1 == 0)
		t1 = M;
	t1--;
	t2 = power(n);
	if(t2 == 0)
		t2 = M;
	t2--;
	p = 1000000005;
	t3 = 1;
	while(p > 0){
		lt1 = (lli)t3 * t2;
		t3 = lt1 % M;
		p >>= 1;
		lt1 = (lli)t2 * t2;
		t2 = lt1 % M;
	}
	lt1 = (lli)t1 * t3;
	rem = lt1 % M;
	printf("%d", rem);
	return 0;
}