#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 1000005
using namespace std;

typedef long long int lli;
char a[N], b[N];

int main() {
	int i, n;
	scanf("%s", a);
	for(i = 0 ; a[i] != '\0' ; i++) {
		if(a[i] == '.')
			break;
	}
	n = i;
	f = 0;
	for(i = 0 ; i < n ; i++) {
		if(a[i] != '0') {
			s = i;
			f = 1;
			break;
		}
	}
	if(f == 0) {
		printf("0");
	}
	else {
		printf("%c", s);
		i = s+1;
		f = 0;
		while(i < n) {
			if(a[i] != '0') {
				f = 1;
				break;
			}
			i++;
		}
		if(f == 1) {
			i = s+1;
			printf(".");
			while(i < n) {
				printf("%c", a[i]);
				i++;
			}
		}
		
	}

}