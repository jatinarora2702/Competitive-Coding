#include <bits/stdc++.h>
#define N 70
using namespace std;
typedef long long int lli;
char s[N];
int a[N];
set < char > st;
map < char, int > mp;
int main() {
	int t, h, b, i, j;
	lli ans;
	scanf("%d", &t);
	h = 0;
	while(t--) {
		h++;
		st.clear();
		mp.clear();
		scanf("%s", s);
		for(i = 0 ; s[i] != '\0' ; i++) {
			st.insert(s[i]);
		}
		b = st.size();
		b = max(2, b);
		a[0] = 1;
		a[1] = 0;
		for(i = 2 ; i < b ; i++) {
			a[i] = i;
		}
		j = 0;
		for(i = 0 ; s[i] != '\0' ; i++) {
			if(mp.find(s[i]) == mp.end()) {
				mp[s[i]] = a[j];
				j++;
			}
		}
		ans = 0LL;
		for(i = 0 ; s[i] != '\0' ; i++) {
			ans = ans * (lli)b + (lli)mp[s[i]];
		}
		cout << "Case #" << h << ": " << ans << "\n";
	}
	return 0;
}