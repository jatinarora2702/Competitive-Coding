#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
int main(){
	int n;
	cin >> n;
	assert(n > 0 && "n must be positive!!");
	n *= 5;
	printf("program running\n");
	assert(("n is not large!!\n", n > 50));
	printf("n = %d\n", n);
	return 0;
}