#include <bits/stdc++.h>
#define N 100005
using namespace std;
char a[N];
int main(){
	int n, f1, f2, cnt, chcnt;
	char ch;
	scanf("%d %s", &n, a);
	ch = '2';
	cnt = 0;
	f1 = f2 = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == ch){
			chcnt++;
			if(chcnt == 2)
				f1++;
			else if(chcnt > 2)
				f2 = 1;
		}
		else{
			chcnt = 1;
			cnt++;
			ch = a[i];
		}
	}
	if(f1 >= 2 || f2 == 1)
		cnt += 2;
	else if(f1 == 1)
		cnt += 1;
	printf("%d", cnt);
	return 0;
}