#include <bits/stdc++.h>
#define N 100005
using namespace std;
char s[N], t[N], temp[N];
int p[N];
int main() {
	int t1, k, k1, k2;
	scanf("%d", &t1);
	while(t1--){
		scanf("%s%s", t, s);
		k = strlen(s);
		k1 = strlen(t);
		k2 = 0;
		for(int i = 0 ; i < k1 ; i++){
			if(t[i] == '*')
				continue;
			temp[k2++] = t[i];
		}
		for(int i = 0 ; i < k ; i++){
			int j, l;
			l = 0;
			for(j = i ; j < k ; j++){
				if(l == k2)
					break;
				if(s[j] == s[l]){
					l++;
					if(l == k2)
						break;
				}
				else
					break;
			}
			if(l == k2)
				p[i] = j+1;
			else
				p[i] = -1;
		}
		for(int i = 0 ; i < k ; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	return 0;
}