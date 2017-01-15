#include <bits/stdc++.h>
#define N 10005
using namespace std;
int s[N], owner[N], valid[N], loss[N], maxm[N];
int getowner(int x){
	if(valid[x])
		return x;
	loss[x] = getowner(loss[x]);
	return loss[x];
}
int main(){
	int t, q, n, x, y, type, ox, oy;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &s[i]);
			valid[i] = 1;
			owner[i] = i;
			maxm[i] = s[i];
		}
		scanf("%d", &q);
		for(int i = 0 ; i < q ; i++){
			scanf("%d", &type);
			if(type == 0){
				scanf("%d%d", &x, &y);
				x--, y--;
				ox = owner[x] = getowner(owner[x]);
				oy = owner[y] = getowner(owner[y]);
				if(ox == oy)
					printf("Invalid query!\n");
				else{
					if(maxm[ox] > maxm[oy]){
						owner[y] = ox;
						valid[oy] = 0;
						loss[oy] = ox;
					}
					else if(maxm[oy] > maxm[ox]){
						owner[x] = oy;
						valid[ox] = 0;
						loss[ox] = oy;
					}
				}
			}
			else if(type == 1){
				scanf("%d", &x);
				x--;
				owner[x] = getowner(owner[x]);
				printf("%d\n", owner[x]+1);
			}
		}
	}
	return 0;
}