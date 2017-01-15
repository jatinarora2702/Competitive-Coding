#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 1005
using namespace std;

typedef long long int lli;

char a[N];
int main() {
	int n, f, l, flag;
	scanf("%s", a);
	n = strlen(a);
	f = 0;
	l = n-1;
	flag = 1;
	while(f <= l) {
		if(a[f] == a[l] && (a[f] == 'o' || a[f] == 'v' || a[f] == 'w' || a[f] == 'x' || a[f] == 'A' || a[f] == 'H' || a[f] == 'I' || a[f] == 'M' || a[f] == 'O' || a[f] == 'T' || a[f] == 'U' || a[f] == 'V' || a[f] == 'Y' || a[f] == 'W' || a[f] == 'X')){
			f++; l--;
			continue;
		}
		if((a[f] == 'b' && a[l] == 'd') || (a[f] == 'd' && a[l] == 'b') || (a[f] == 'p' && a[l] == 'q') || (a[f] == 'q' && a[l] == 'p')){
			f++; l--;
			continue;
		}
		flag = 0;
		break;
	}
	if(flag == 1){
		printf("TAK\n");
	}
	else
		printf("NIE\n");
	return 0;
}