#include <bits/stdc++.h>
#define FF first
#define SS second
using namespace std;

const int N = 100005;

char s[N], t[N], c[30];
int a[N];

map < char, int > mp;

int main() {
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for(i = 0 ; i < n ; i++) {
		a[s[i]-'a']++;
	}
	j = 0;
	for(i = 0 ; i < 26 ; i++) {
		if(a[i] > 0) {
			c[j] = 'a' + i;
			mp['a' + i] = j;
			j++;
		}
	}
	c[j] = c[0];
	// for(i = 0 ; i < j ; i++) {
	// 	printf("%c ", c[i]);
	// }
	// printf("\n");
	// for(map < char, int > :: iterator it = mp.begin() ; it != mp.end() ; it++) {
	// 	printf("(%d, %d) ", it->FF, it->SS);
	// }
	// printf("\n");
	if(k > n) {
		for(i = 0 ; i < n ; i++) {
			t[i] = s[i];
		}
		for(i = n ; i < k ; i++)
			t[i] = c[0];
	}
	else {
		for(i = 0 ; i < k ; i++)
			t[i] = s[i];
		i--;
		while(i >= 0) {
			j = mp[t[i]] + 1;
			t[i] = c[j];
			if(c[j] != c[0])
				break;
			i--;
		}
	}
	t[k] = '\n';
	printf("%s", t);
	return 0;
}