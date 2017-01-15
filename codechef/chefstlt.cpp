#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, cnt, cntdbt;
	char *a, *b;
	a = new char[101];
	b = new char[101];
	scanf("%d", &t);
	while(t--) {
		scanf("%s%s", a, b);
		cnt = cntdbt = 0;
		for(int i = 0 ; a[i] != '\0' ; i++){
			if(a[i] == '?' || b[i] == '?')
				cntdbt++;
			else if(a[i] != b[i])
				cnt++;
		}
		printf("%d %d\n", cnt, cnt+cntdbt);
	}
	return 0;
}