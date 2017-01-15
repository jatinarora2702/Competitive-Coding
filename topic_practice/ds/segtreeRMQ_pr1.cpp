#include <bits/stdc++.h>
using namespace std;
void constructST_util(int *st, int ss, int se, int *a, int index) {
	if()
}
int* constructST(int *a, int n) {
	int x = log2(n);
	x = 2 * pow(2,x) - 1;
	int *st = new int[x];
	constructST_util(st,0,n-1,a,0);
	return st;
}
int main() {
	int n;
	cout << "IMPLEMENTATION OF RANGE MINIMUM QUERY USING SEGMENT TREE\n\n";
	cout << "Enter the no. of elements in the array : ";
	cin >> n;
	a = new int[n];
	cout << "Enter the array elements :\n";
	for(int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
	}
	cout << "Array elements are : ";
	for(int i = 0 ; i < n ; i++ ) {
		cout << "a[" << i << "] = " << a[i] << " ";
	}
	cout << endl;
	cout << "Enter the range over which the minimum element is to be found :\n";
	cin >> qs >> qe;
	st = constructST(a,n);
	min = get_min(st,0,n-1);
	cout << "min is : " << min << endl;
	return 0;	
}