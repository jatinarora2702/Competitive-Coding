#include <bits/stdc++.h>
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
using namespace std;

int main(){
	int a, b, c, x, y, z, s, cnt;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
	s = a + b + c - x - y -z;
	cnt = 0;
	while(a > x){
		a -= 2;
		cnt++;
	}
	while(a < x){
		a++;
		cnt++;
	}
	if(cnt > s)
		printf("No\n");
	else{
		cnt = 0;
		while(c > z){
			c -= 2;
			cnt++;
		}
		while(c < z){
			c++;
			cnt++;
		}
		if(cnt > s)
			printf("No\n");
		else{
			cnt = 0;
			while(b > y){
				b -= 2;
				cnt++;
			}
			while(b < y){
				b++;
				cnt++;
			}
			if(cnt > s)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
}
