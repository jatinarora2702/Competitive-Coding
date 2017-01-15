#include <bits/stdc++.h>
#define FF first
#define SS second
using namespace std;
typedef long long int lli;
int main(){
	pair < lli, lli > p[3];
	for(int i = 0 ; i < 3 ; i++){
		cin >> p[i].FF >> p[i].SS;
	}
	if(((p[0].FF == p[1].FF) && (p[1].FF == p[2].FF)) || ((p[0].SS == p[1].SS) && (p[1].SS == p[2].SS)))
		printf("1\n");
	else{
		if(((p[0].FF == p[1].FF) || (p[0].FF == p[2].FF) || (p[1].FF == p[2].FF)) && ((p[0].SS == p[1].SS) || (p[0].SS == p[2].SS) || (p[1].SS == p[2].SS))){
			printf("2\n");
		}
		else
			printf("3\n");
	}
	return 0;
}