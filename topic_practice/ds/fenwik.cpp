#include <iostream>
#include <stdio.h>
using namespace std;
void update(int *fen, int n, int val, int index){
	index++;
	for(int i  = index ; i <= n ; i += i & (-i))
		fen[i] += val;
}
int getsum(int *fen , int n, int index){
	index++;
	int sum = 0;
	for(int i = index ; i > 0 ; i -= i & (-i))
		sum += fen[i];
	return sum;
}
int main(){
	int n, *fen, *arr;
	scanf("%d", &n);
	arr = new int[n];
	fen = new int[n+1];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &arr[i]);
	}
	cout << "dd\n";
	for(int i = 0 ; i < n ; i++)
		update(fen, n, arr[i], i);
	printf("%d\n", getsum(fen, n, n-1));
	update(fen, n, 4, 1);
	printf("%d\n", getsum(fen, n, n-1));
	return 0;
}