#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define N 50
using namespace std;
typedef long long int lli;
char s1[N], s2[N], s3[N];
int main(){
	int n;
	scanf("%s %s %s", s1, s2, s3);
	n = atoi(s1);
	if(s3[0] == 'w'){
		if(n == 5 || n == 6)
			printf("53");
		else
			printf("52");
	}
	else{
		if(n == 30)
			printf("11");
		else if(n == 31)
			printf("7");
		else
			printf("12");
	}
	return 0;
}