#include <bits/stdc++.h>
#define N 5000000
using namespace std;
int arr[N];
int frfac[N];
int p[N];
int k;
void getfirstfactor(int n){
	//cout << n << endl;
	for(int i = 0 ; i < k ; i++){
		if(n % p[i] == 0){
			frfac[n] = p[i];
			return;
		}
	}
	for(int i = p[k-1]+1 ; i < sqrt(n) ; i+=2){
		if(n % i == 0){
			frfac[n] = i;
			return;
		}
	}
	frfac[n] = n;
	p[k] = n;
	k++;
}
void getpfacts(){
	arr[0] = 0;
	arr[1] = 0;
	for(int i = 2 ; i <= N ; i++){
		getfirstfactor(i);
		if(frfac[i] == i)
			arr[i] = 1;
		else
			arr[i] = arr[i/frfac[i]]+1;
		cout << arr[i] << endl;
	}
}
int main() {
	int t, a, b, cnt;
	scanf("%d", &t);
	p[0] = 2;
	k = 1;
	getpfacts();
	while(t--){
		scanf("%d%d", &a, &b);
		cnt = 0;
		for(int i = b+1 ; i <= a ; i++)
			cnt += arr[i];
		printf("%d\n", cnt);
	}
	return 0;
}