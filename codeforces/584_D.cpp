#include <bits/stdc++.h>
#define N 505
using namespace std;
int mark[N];
int isprime(int n){
	int k = sqrt(n), f = 1;
	for(int i = 3 ; i <= k ; i+=2){
		if(n % i == 0){
			f = 0;
			break;
		}
	}
	return f;
}
int main(){
	int n, f1, f2, f3, k, n1, n2, n3;
	k = 0;
	for(int i = 2 ; i < N ; i++){
		if(mark[i] == 0){
			mark[i] = 1;
			for(int j = 2*i ; j < N ; j += i)
				mark[j] = -1;
		}
	}
	// for(int i = 2 ; i < N ; i++)
	// 	if(mark[i] == 1)
	// 		printf("%d ", i);
	// printf("\n");
	scanf("%d", &n);
	f1 = isprime(n);
	if(f1 == 1){
		printf("1\n%d", n);
	}
	else{
		f2 = isprime(n-2);
		if(f2 == 1){
			printf("2\n%d 2", n-2);
		}
		else{
			for(int i = 4 ; i <= 500 ; i += 2){
				if(isprime(n-i)){
					n1 = n-i;
					if(i == 4){
						printf("3\n%d 2 2", n1);
						break;
					}
					for(int j = 3 ; j < i ; j += 2){
						if(mark[j] == 1 && mark[i-j] == 1){
							n2 = j;
							n3 = i-j;
							break;
						}
					}
					printf("3\n%d %d %d", n1, n2, n3);
					break;
				}
			}
		}
	}
	return 0;
}