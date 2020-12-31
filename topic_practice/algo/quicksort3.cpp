#include <bits/stdc++.h>
using namespace std;

typedef vector<int>::iterator vit;

int part(vit begin, vit end) {
	vit it1 = begin + 1;
	vit it2 = end - 1;
	while(it1 != it2) {
		while(*it1 <= *begin && it1 != it2) {
			it1++;
		}
		while(*it2 > *begin && it1 != it2) {
			it2--;
		}
		if (it1 != it2) {
			int k = *it1;
			*it1 = *it2;
			*it2 = k;
			it1++;
			if (it1 == it2) {
				break;
			}
			it2--;
		}
	}
	if (*it2 > *begin) {
		it2--;
	}
	int k = *begin;
	*begin = *it2;
	*it2 = k;
	return it2 - begin;
}

void print(vit begin, vit end) {
	cout << "vec: ";
	for(vit it = begin; it != end; it++) {
		cout << *it << " ";
	}
	cout << "\n";
}

void qs(vit begin, vit end) {
	if ((begin == end) || ((begin + 1) == end)) {
		return;
	}
	int k = part(begin, end);
	qs(begin, begin + k);
	qs(begin + k + 1, end);
}

int main() {
	vector<int> v {9, 5, 1, 2, 7, 9, 2, 3, 8};
	qs(v.begin(), v.end());
	print(v.begin(), v.end());
	return 0;
}