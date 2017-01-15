#include <bits/stdc++.h>
#define N 100005
#define PB push_back
using namespace std;
char a[N], b[N], c[N];
vector < int > diff;
int used[N], changed[N];
int main(){
	int t, n, cnt, acnt, bcnt, changecnt, f, more, amore, bmore;
	scanf("%d%d%s%s", &n, &t, a, b);
	cnt = 0;
	for(int i = 0 ; i <= n ; i++){
		if(a[i] != b[i]){
			cnt++;
			diff.PB(i);
		}
		c[i] = a[i];
	}
	c[n] = '\0';
	if(cnt <= t){
		changecnt = 0;
		for(int i = 0 ; i < diff.size() ; i++){
			used[a[diff[i]]-'a'] = 1;
			used[b[diff[i]]-'a'] = 1;
			for(int j = 0 ; j < 26 ; j++){
				if(used[j] == 0){
					c[diff[i]] = j+'a';
					break;
				}
			}
			used[a[diff[i]]-'a'] = 0;
			used[b[diff[i]]-'a'] = 0;
			changecnt++;
			changed[diff[i]] = 1;
		}
		for(int i = 0 ; i < n ; i++){
			if(changed[i] == 0 && changecnt < t){
				used[a[i]-'a'] = 1;
				used[b[i]-'a'] = 1;
				for(int j = 0 ; j < 26 ; j++){
					if(used[j] == 0){
						c[i] = j+'a';
						break;
					}
				}
				used[a[i]-'a'] = 0;
				used[b[i]-'a'] = 0;
				changecnt++;
				changed[i] = 1;
			}
		}
		if(changecnt < t)
			f = 0;
		else 
			f = 1;
	}
	else{
		more = cnt - t;
		acnt = bcnt = 0;
		amore = bmore = 0;
		// printf("diff=%ld\n", diff.size());
		for(int i = 0 ; i < diff.size() ; i++){
			if(amore < more){
				// printf("ii\n");
				amore++;
				c[diff[i]] = a[diff[i]];
				bcnt++;
				changed[diff[i]] = 1;
			}
			else if(bmore < more){
				// printf("uu\n");
				c[diff[i]] = b[diff[i]];
				acnt++;
				bmore++;
				changed[diff[i]] = 1;
			}
			else if(acnt < t){
				// printf("qq\n");
				acnt++;
				bcnt++;
				used[a[diff[i]]-'a'] = 1;
				used[b[diff[i]]-'a'] = 1;
				for(int j = 0 ; j < 26 ; j++){
					if(used[j] == 0){
						c[diff[i]] = j+'a';
						break;
					}
				}
				used[a[diff[i]]-'a'] = 0;
				used[b[diff[i]]-'a'] = 0;
				changed[diff[i]] = 1;
			}
		}
		// printf(":%s\n", c);
		if(amore < more || bmore < more){
			// printf("qq	qqq\n");
			printf("-1");
			return 0;
		}
		// printf("pp\n");
		for(int i = 0 ; i < n ; i++){
			if(acnt >= t)
				break;
			if(changed[i] == 0){
				acnt++;
				used[a[i]-'a'] = 1;
				used[b[i]-'a'] = 1;
				for(int j = 0 ; j < 26 ; j++){
					if(used[j] == 0){
						c[i] = j+'a';
						break;
					}
				}
				used[a[i]-'a'] = 0;
				used[b[i]-'a'] = 0;
				changed[i] = 1;
			}
		}
		if(acnt < t)
			f = 0;
		else 
			f = 1;
	}
	if(f == 0)
		printf("-1");
	else
		printf("%s", c);
	return 0;
}