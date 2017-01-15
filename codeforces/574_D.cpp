#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, *a, lvl, minm, k, f, *b;
	vector < int > v1, v2;
	scanf("%d", &n);
	a = new int[n];
	b = new int[n];
	for(int i = 0 ; i < n; i++){
		scanf("%d", &a[i]);
	}
	v1.push_back(a[0]);
	v1.push_back(0);
	b[0] = 1;
	f = 0;
	for(int i = 1 ; i < n ; i++){
		k = 0;
		if(f == 0){
			v2.push_back(a[i]);
			while(v2[k] != 0){
				k++;
				minm = v2[k-1]-v1[k-1];
				if(minm < 1)
					minm = 1;
				v2.push_back(v2[k-1]-minm);
			}
			b[i] = k;	
			// cout << "k1=" << k << " ";
			// for(int k1 = 0 ; k1 < v2.size() ; k1++)
			// 	cout << v2[k1] << " ";
			// cout << endl;
			f ^= 1;
			v1.clear();
		}
		else{
			v1.push_back(a[i]);
			while(v1[k] != 0){
				k++;
				minm = v1[k-1]-v2[k-1];
				if(minm < 1)
					minm = 1;
				v1.push_back(v1[k-1]-minm);
			}
			b[i] = k;
			// cout << "k2=" << k << " ";
			// for(int k1 = 0 ; k1 < v1.size() ; k1++)
			// 	cout << v1[k1] << " ";
			// cout << endl;
			f ^= 1;	
			v2.clear();
		}
	}
	v1.clear();
	v2.clear();
	v1.push_back(a[n-1]);
	v1.push_back(0);
	b[n-1] = 1;
	f = 0;
	for(int i = n-2 ; i >= 0 ; i--){
		k = 0;
		if(f == 0){
			v2.push_back(a[i]);
			while(v2[k] != 0){
				k++;
				minm = v2[k-1]-v1[k-1];
				if(minm < 1)
					minm = 1;
				v2.push_back(v2[k-1]-minm);
			}
			// cout << "k3=" << k << " ";
			// for(int k1 = 0 ; k1 < v2.size() ; k1++)
			// 	cout << v2[k1] << " ";
			// cout << endl;
			if(b[i] > k)
				b[i] = k;	
			f ^= 1;
			v1.clear();
		}
		else{
			v1.push_back(a[i]);
			while(v1[k] != 0){
				k++;
				minm = v1[k-1]-v2[k-1];
				if(minm < 1)
					minm = 1;
				v1.push_back(v1[k-1]-minm);
			}
			// cout << "k4=" << k << " ";
			// for(int k1 = 0 ; k1 < v1.size() ; k1++)
			// 	cout << v1[k1] << " ";
			// cout << endl;
			if(b[i] > k)
				b[i] = k;
			f ^= 1;	
			v2.clear();
		}
	}
	// for(int i = 0 ; i < n ; i++)
	// 	cout << b[i] << " pp" << endl;
	lvl = b[0];
	for(int i  = 1 ; i < n ; i++)
		if(b[i] > lvl)
			lvl = b[i];
	printf("%d", lvl);
	return 0;
}