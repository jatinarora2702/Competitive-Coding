#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int *a, *b, na, nb, k, m;
	scanf("%d%d%d%d", &na, &nb, &k, &m);
	a = new int[na];
	b = new int[nb];
	for(int i = 0 ; i  < na ; i++)
		scanf("%d", &a[i]);
	for(int i  = 0 ; i < nb ; i++)
		scanf("%d", &b[i]);
	k--;
	if(a[k] < b[nb-m])
		printf("YES");
	else
		printf("NO");
	return 0;
}