#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
	pair < int, int > p1, p2, p3, p4;
	double d;
	int flag;
	scanf("%d%d%d%d", &p1.f, &p1.s, &p2.f, &p2.s);
	flag = 1;
	//printf("pp\n");
	if(p1.f - p2.f == 0){
		d = abs(p1.s - p2.s);
		if(p1.f - d >= -1000 and p2.f - d >= -1000){
			p3.f = p1.f - d;
			p4.f = p2.f - d;
			p3.s = p1.s;
			p4.s = p2.s;
		}
		else if(p1.f + d <= 1000 and p2.f + d <= 1000){
			p3.f = p1.f + d;
			p4.f = p2.f + d;
			p3.s = p1.s;
			p4.s = p2.s;	
		}
		else
			flag = 0;
	}
	else if(p1.s - p2.s == 0){
		d = abs(p1.f - p2.f);
		if(p1.s - d >= -1000 and p2.s - d >= -1000){
			p3.s = p1.s - d;
			p4.s = p2.s - d;
			p3.f = p1.f;
			p4.f = p2.f;
		}
		else if(p1.s + d <= 1000 and p2.s + d <= 1000){
			p3.s = p1.s + d;
			p4.s = p2.s + d;
			p3.f = p1.f;
			p4.f = p2.f;	
		}
		else
			flag = 0;
	}
	else{
		double slp = (double)(p2.s - p1.s) / (double)(p2.f - p1.f);
		if(slp == 1){
			p3.f = p1.f;
			p3.s = p2.s;
			p4.f = p2.f;
			p4.s = p1.s;
		}
		else if(slp == -1){
			p3.f = p1.f;
			p3.s = p2.s;
			p4.f = p2.f;
			p4.s = p1.s;	
		}
		else
			flag = 0;
	}
	if(flag == 0)
		printf("-1");
	else{
		printf("%d %d %d %d", p3.f, p3.s, p4.f, p4.s);
	}
	return 0;
}