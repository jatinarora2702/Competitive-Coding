#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long int lli;
const int INF = 1e9+7;
char s[N];
set < char > st;
int main() {
	int t, ans, i, k, h;
	lli temp;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		scanf("%s", s);
		ans = 1;
		for(i = 0 ; s[i] != '\0' ; i++) {
			st.clear();
			st.insert(s[i]);
			if(i-1 >= 0) st.insert(s[i-1]);
			if(s[i+1] != '\0') st.insert(s[i+1]);
			temp = (lli)ans * (lli)st.size();
			temp %= (lli)INF;
			ans = temp;
		}
		printf("Case #%d: %d\n", h, ans);
	}
	return 0;
}