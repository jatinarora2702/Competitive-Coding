#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long int ulli;
ulli gcd(ulli a, ulli b) {
	ulli temp;
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}
	while(b > 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
void fn(ulli a, ulli b) {
	ulli c, q;
	c = gcd(a,b);
	if(c == 1 and b == 1){
		printf("Yes\n");
		return;
	}
	else if(c == 1 and b != 1){
		printf("No\n");
		return;
	}
	q = b / c;
	fn(c,q);
}
int main() {
	int t;
	ulli a, b, c, q, r;
	scanf("%d", &t);
	while(t--){
		scanf("%llu%llu", &a, &b);
		fn(a,b);
		/*
		c = gcd(a,b);
		//cout << "c=" << c << endl;
		q = b / c;
		//cout << "q=" << q << endl;
		if(c == 1 and b != 1){
			printf("No\n");
			continue;
		}
		else if(c == 1 and b == 1){
			printf("Yes\n");
			continue;
		}
		else{
			while(1){
				r = q % c;
				if(r != 0)
					break;
				q = q / c;
			}
			r = c % q;
			//cout << "r=" << r << endl;
			if(r == 0)
				printf("Yes\n");
			else
				printf("No\n");
		}
		*/
	}
	return 0;
}