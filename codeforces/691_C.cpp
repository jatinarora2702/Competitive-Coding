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
	int i, j, n, flag, b1, b2, c1, c2, f, p;
	scanf("%s", a);
	n = 0;
	f = 0;
	flag = 0;
	j = 0;
	for(i = 0 ; a[i] != '\0' ; i++) {
		if(f == 0) {
			if(a[i] == '.'){
				printf("0");
				c2 = 0;
				f = 3;
			}
			else if(a[i] != '0') {
				printf("%c", a[i]);
				c1 = 0;
				f = 1;
			}
		}
		else if(f == 1) {
			if(a[i] == '.') {
				f = 3;
				c2 = 0;
			}
			else if(a[i] != '0') {
				f = 2;
				c1++;
				printf(".%c", a[i]);
			}
			else{
				c1++;
			}
		}
		else if(f == 2) {
			if(a[i] == '.') {
				f = 3;
				c2 = 0;
			}
			else {
				c1++;
				printf("%c", a[i])
			}
		}
		else if(f == 3) {
			
		}
		if(a[i] == '.') {
			f = 1;
			n = 0;
			continue;
		}
		if(f == 1) {
			n++;
			if(a[i] != '0')
				flag = 1;
		}
	}
	i--;
	while(i >= 0 && a[i] == '0') {
		i--;
	}
	j = i;
	i = 0;
	while(a[i] == '0' && a[i] != '\0')
		i++;
	if(a[i] == '\0')
		printf("0\n");
	else {
		if(a[i] == '.'){
			printf("0.");
			i++;
		}
		else {
			printf("%c.", a[i]);
			i++;
			while(a[i] != '.' && a[i] != '\0') {
				printf("%c", a[i]);
				i++;
			}
		}
		if(a[i] != '\0') {
			while(i <= j){
				printf("%c", a[i]);
				i++;
			}
		}
		if(n > 0) {
			printf("E%d", n);
		}
		printf("\n");
	}
	return 0;
}