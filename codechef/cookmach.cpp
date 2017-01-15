#include <iostream>
#include <cstdio>
#include <set>
#define N 10000007
using namespace std;
int main() {
	int t, a, b, c;
	scanf("%d", &t);
	set < int > pw;
	int k = 1;
	while(k < N){
		pw.insert(k);
		k *= 2;
	}
	while(t--){
		scanf("%d %d", &a, &b);
		c = 0;
		while(pw.find(a) == pw.end()){
			c++;
			a /= 2;
		}
		if(a < b){
			while(a < b){
				c++;
				a *= 2;
			}	
		}
		else if(a > b){
			while(a > b){
				c++;
				a /= 2;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}