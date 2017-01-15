#include <bits/stdc++.h>
#define N 100005
#define MP make_pair
using namespace std;
char a[N];
int b[N];
map < pair < int, int > , int > maps;
int main(){
	int nx, ny, x, y, x1, y1, n;
	scanf("%d%d%d%d", &nx, &ny, &x, &y);
	scanf(" %s", a);
	for(int i = 0 ; i < N ; i++)
		b[i] = 0;
	b[0] = 1;
	maps[MP(x, y)] = 1;
	for(n = 0 ; a[n] != '\0' ; n++);
	for(int i = 0 ; i < n ; i++){
		switch(a[i]){
			case 'L': y1 = y-1; x1 = x; break;
			case 'R': y1 = y+1; x1 = x; break;
			case 'U': x1 = x-1; y1 = y; break;
			case 'D': x1 = x+1; y1 = y; break;
		}
		// printf("(%d, %d) ", x1, y1);
		if(x1 <= nx && y1 <= ny && x1 > 0 && y1 > 0){
			if(maps[MP(x1, y1)] == 0){
				b[i+1]++;
				maps[MP(x1, y1)] = 1;	
			}
			x = x1;
			y = y1;
		}
	}
	b[n] += nx * ny - maps.size();
	for(int i = 0 ; i <= n ; i++)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}