#include <bits/stdc++.h>
#define N 100005
using namespace std;
vector < int > v;
bool fn(int a, int b){
	return (a > b);
}
int main(){
	int n, x, k;
	long long int sum;
	scanf("%d", &n);
	sum = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &x);
		if(x % 2 == 0)
			sum += (long long int)x;
		else
			v.push_back(x);
	}
	sort(v.begin(), v.end(), fn);
	if(v.size() % 2 == 0)
		k = v.size();
	else
		k = v.size() - 1;
	for(int i = 0 ; i < k ; i++){
		sum += (long long)v[i];
	}
	cout << sum << endl;
}