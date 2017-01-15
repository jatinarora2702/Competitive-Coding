#include <bits/stdc++.h>
#define N 15
using namespace std;
int main() {
	char a[N], b[N];
	int t, flag;
	scanf("%d", &t);
	while(t--){
		scanf("%s%s", a, b);
		flag = 1;
		for(int i = 0 ; a[i] != '\0' ; i++){
			if(a[i] != '?' && b[i] != '?'){
				if(a[i] != b[i])
					flag = 0;
			}
		}
		if(flag == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}