#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, pos, p, rem, flag;
	// printf("Enter a no. to find if it is lucky : ");
	// scanf("%d", &n);
	for(n = 1 ; n <= 100000 ; n++){
		p = 2;
		pos = n;
		flag = 1;
		while(p <= pos){
			rem = pos % p;
			if(rem == 0){
				flag = 0;
				break;
			}
			pos = pos - (pos / p);
			p++;
		}
		if(flag == 1)
			printf("%d\t", n);
		// if(flag == 0)
		// 	printf("No. is not lucky!\n");
		// else
		// 	printf("No. is lucky!\n");
	}
	cout << endl;
	return 0;
}