#include <bits/stdc++.h>
using namespace std;
int get_mid(int s, int e) {
	return s + (e - s) / 2;
}
int get_sum_util(int *st, int ss, int se, int qs, int qe, int index) {
	if(qs > se or qe < ss)
		return 0;
	else if(qs <= ss and qe >= se){
		return st[index];
	}
	else {
		int mid = ss + (se - ss) / 2;
		return get_sum_util(st,ss,mid,qs,qe,2*index + 1) + get_sum_util(st,mid + 1,se,qs,qe,2*index + 2);
	}
}
int get_sum(int *st, int n, int qs, int qe) {
	if(qs < 0 or qs > n - 1 or qe < 0 or qe > n - 1 or qs > qe) {
		cout << "\nERROR : invalid input\n";
		return -1; // invalid input
	}
	return get_sum_util(st,0,n-1,qs,qe,0);
}
void update_value_util(int *st, int ss, int se, int diff, int index, int idx) {
	if(idx < ss or idx > se)
		return;
	st[index] += diff;
	if(ss == se) 
		return;
	int mid = get_mid(ss,se);
	update_value_util(st,ss,mid,diff,2*index + 1,idx);
	update_value_util(st,mid+1,se,diff,2*index + 2,idx);
}
void update_value(int *st, int *a, int n, int val, int idx) {
	if(idx < 0 or idx > n - 1) {
		cout << "\nERROR : invalid index updation\n";
		return;
	}
	int diff = val - a[idx];
	a[idx] = val;
	update_value_util(st,0,n-1,diff,0,idx);
}
int constructST_util(int *st, int ss, int se, int* a, int index) {
	if(ss == se) {
		st[index] = a[ss];
		return st[index];
	}
	int mid = get_mid(ss,se);
	st[index] = constructST_util(st,ss,mid,a,2*index + 1) + constructST_util(st,mid+1,se,a,2*index + 2);
	return st[index];
}
int* constructST(int *a, int n) {
	int x = ceil(log2(n));
	x = 2 * pow(2,x) - 1;
	int *st = new int[x];
	constructST_util(st,0,n-1,a,0);
	return st;
}
int main() {
	int n,*a,qs,qe,*st,sum,index,val;
	cout << "IMPLEMENTATION OF SEGMENT TREES :\n\n";
	cout << "Enter the no. of elements in the array : ";
	cin >> n;
	cout <<  "Enter the no.s :\n";
	a = new int[n];
	for(int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
	}
	st = constructST(a,n);
	cout << "\nEnter the range (left-right) between which you wish to find the sum : ";
	cin >> qs >> qe;
	sum = get_sum(st,n,qs,qe);
	cout << "\nsum is : " << sum << endl;
	cout << "Enter the index in the array which needs to be updated : ";
	cout << endl << "The array is : \n";
	for(int i = 0 ; i < n ; i++ ) {
		cout << "arr[" << i << "] = " << a[i] << " ";
	}
	cout << endl << "Enter index : ";
	cin >> index;
	cout << "Enter new value : ";
	cin >> val;
	update_value(st,a,n,val,index);
	cout << "Specify new range to find sum : ";
	cin >> qs >> qe;
	sum = get_sum(st,n,qs,qe);
	cout << "New sum is : " << sum << endl;
	return 0;
}