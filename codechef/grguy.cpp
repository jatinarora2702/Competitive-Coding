#include <iostream>
#include <cstdio>
#define N 200005
#define INF 1000000000
using namespace std;
int main(){
	char a[N], b[N];
	int t, i, c1, c2, f, p;
	scanf("%d", &t);
	while(t--){
		c1 = c2 = INF;
		scanf("%s %s", a, b);
		if(a[0] == '#' && b[0] == '#')
			p = 0;
		else
			p = 1;
		if(p == 1 && a[0] == '.'){
			f = 1;
			c1 = 0;
			i = 0;
			while(true){
				if(f == 1){
					if(a[i+1] == '\0')
						break;
					if(a[i+1] == '#'){
						c1++;
						f = 2;
						if(b[i+1] == '#'){
							p = 0;
							break;
						}
						i++;
					}
					else
						i++;
				}
				else{
					if(b[i+1] == '\0')
						break;
					if(b[i+1] == '#'){
						c1++;
						f = 1;
						if(a[i+1] == '#'){
							p = 0;
							break;
						}
						i++;
					}
					else
						i++;
				}
			}
		}
		if(p != 0 && b[0] == '.'){
			f = 2;
			c2 = 0;
			i = 0;
			while(true){
				if(f == 1){
					if(a[i+1] == '\0')
						break;
					if(a[i+1] == '#'){
						c2++;
						f = 2;
						if(b[i+1] == '#'){
							p = 0;
							break;
						}
						i++;
					}
					else
						i++;
				}
				else{
					if(b[i+1] == '\0')
						break;
					if(b[i+1] == '#'){
						c2++;
						f = 1;
						if(a[i+1] == '#'){
							p = 0;
							break;
						}
						i++;
					}
					else
						i++;
				}
			}
		}
		if(p == 0)
			printf("No\n");
		else
			printf("Yes\n%d\n", min(c1, c2));
	}
	return 0;
}