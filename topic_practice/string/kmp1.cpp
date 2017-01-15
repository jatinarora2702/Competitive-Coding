#include <bits/stdc++.h>
using namespace std;
char a[N], b[N];
int p[N];
int main(){
	int m, n;
	printf("Enter string and pattern:\n");
	scanf("%s%s", a, b);
	m = strlen(a);
	n = strlen(b);
	for(int i = 0 ; i < n ; i++){
		
	}
	k = 0;
	for(int i = 0 ; i < m ; i++){
		if(a[i] == b[k]){
			k++;
			if(k == n){
				printf("Found pattern starting at: %d\n", i-n+1);
			}
			else
				k = p[k];
		}
	}
}