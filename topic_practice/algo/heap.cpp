#include <bits/stdc++.h>
using namespace std;

void makeheap(int a[], int n, vector<int>& h) {
	for(int i = 0; i < n; i++) {
		h.push_back(a[i]);
	}
	int j = (n-2) / 2;
	while(j >= 0) {
		int i = j;
		while(true) {
			if (2*i+2 < n) {
				int m = (h[2*i+1] <= h[2*i+2]) ? (2*i+1) : (2*i+2);
				if (h[i] > h[m]) {
					int t = h[i];
					h[i] = h[m];
					h[m] = t;
					i = m;
				}
				else {
					break;
				}
			}
			else if (2*i+1 < n && h[i] > h[2*i+1]) {
				int t = h[2*i+1];
				h[2*i+1] = h[i];
				h[i] = t;
				i = 2*i+1;
			}
			else {
				break;
			}
		}
		j--;
	}
}

void insert(vector<int>& h, int x) {
	h.push_back(x);
	int n = h.size();
	int i = n-1;
	while((i-1)/2 >= 0 && h[(i-1)/2] > h[i]) {
		int t = h[i];
		h[i] = h[(i-1)/2];
		h[(i-1)/2] = t;
		i = (i-1)/2;
	}
}

void del(vector<int>& h, int x) {
	int n, i;
	n = h.size();
	for(i = 0; i < n; i++) {
		if (h[i] == x) {
			break;
		}
	}
	int t = h[n-1];
	h[n-1] = h[i];
	h[i] = t;
	h.pop_back();
	n--;
	
	if (h[i] < x) {
		while((i-1)/2 >= 0 && h[(i-1)/2] > h[i]) {
			t = h[i];
			h[i] = h[(i-1)/2];
			h[(i-1)/2] = t;
			i = (i-1)/2;
		}
	}
	else {
		while(true) {
			if (2*i+2 < n) {
				int m = (h[2*i+1] <= h[2*i+2]) ? (2*i+1) : (2*i+2);
				if (h[i] > h[m]) {
					int t = h[i];
					h[i] = h[m];
					h[m] = t;
					i = m;
				}
				else {
					break;
				}
			}
			else if (2*i+1 < n && h[i] > h[2*i+1]) {
				int t = h[2*i+1];
				h[2*i+1] = h[i];
				h[i] = t;
				i = 2*i+1;
			}
			else {
				break;
			}
		}
	}
}

void hsort(vector<int>& h, vector<int>& sh) {
	int n = h.size();
	for(int i = 0; i < n; i++) {
		sh.push_back(h[0]);
		del(h, h[0]);
	}
}

int main() {
	int a[] = {5, 6, 9, 1, 3, 5, 2};
	int n = 7;
	vector<int> h;
	makeheap(a, n, h);
	for(int i = 0; i < h.size(); i++) {
		cout << h[i] << " ";
	}
	cout << "\n";
	insert(h, 1);
	for(int i = 0; i < h.size(); i++) {
		cout << h[i] << " ";
	}
	cout << "\n";
	del(h, 2);
	for(int i = 0; i < h.size(); i++) {
		cout << h[i] << " ";
	}
	cout << "\n";
	vector<int> hs;
	hsort(h, hs);
	for(int i = 0; i < hs.size(); i++) {
		cout << hs[i] << " ";
	}
	cout << "\n";
	return 0;
}