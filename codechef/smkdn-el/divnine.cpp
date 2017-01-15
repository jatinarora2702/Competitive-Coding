#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, rem, sum, cnt;
	char s[100005];
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		sum = 0;
		cnt = 0;
		for(int i = 0 ; s[i] != '\0' ; i++){
			cnt++;
			sum += (s[i] - '0');
		}
		rem = sum % 9;
		if(rem == 0)
			printf("0\n");
		else{
			if(sum < 9){
				if(cnt == 1)
					printf("%d\n", min(rem, 9-rem));
				else
					printf("%d\n", 9-rem);
			}
			else
				printf("%d\n", min(rem, 9-rem));
		}
	}
	return 0;
}