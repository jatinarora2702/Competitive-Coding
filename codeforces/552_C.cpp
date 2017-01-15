#include <iostream>
#include <stdio.h>
using namespace std;
bool fn(int w, int m, int level){
	if(level > 100)
		return false;
	if(m == 0 or m == 1 or m == -1)
		return true;
	if(m % w == 0 and fn(w, m/w, level+1))
		return true;
	if((m-1) % w == 0 and fn(w, (m-1)/w, level+1))
		return true;
	if((m+1) % w == 0 and fn(w, (m+1)/w, level+1))
		return true;
	return false;
}
int main(){
	int w, m;
	scanf("%d%d", &w, &m);
	if(fn(w, m, 0))
		printf("YES");
	else
		printf("NO");
	return 0;
}