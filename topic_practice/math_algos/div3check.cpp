#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, sum_o, sum_e;
	printf("Enter no. to check divisibility by 3 : ");
	scanf("%d", &n);
	if(n < 0)
		n = -n;
	sum_o = sum_e = 0;
	while(n > 0){
		if(n & 1)
			sum_o++;
		n >>= 1;
		if(n & 1)
			sum_e++;
		n >>= 1;
	}
	// cout << sum_e << " " << sum_o << endl;
	if((sum_e - sum_o) % 3 == 0)
		printf("is divisible!\n");
	else
		printf("not divisible!\n");
	return 0;
}