#include <bits/stdc++.h>
#define FF first
#define SS second
using namespace std;

typedef pair < int, int > pii;

int onseg(pii p1, pii p2, pii p3) {
	if(p2.FF <= max(p1.FF, p3.FF) && p2.FF >= min(p1.FF, p3.FF) && p2.SS >= min(p1.SS, p3.SS) && p2.SS <= max(p1.SS, p3.SS)) {
		return 1;
	}
	return 0;
}

int orientation(pii p1, pii p2, pii p3) {
	int x = (p3.SS - p2.SS) * (p2.FF - p1.FF) - (p3.FF - p2.FF) * (p2.SS - p1.SS);
	if(x == 0)
		return 0;
	return (x < 0) ? -1 : 1;
}

int main() {
	pii p1, p2, p3, p4;
	int o1, o2, o3, o4;
	cin >> p1.FF >> p1.SS;
	cin >> p2.FF >> p2.SS;
	cin >> p3.FF >> p3.SS;
	cin >> p4.FF >> p4.SS;
	o1 = orientation(p1, p2, p3);
	o2 = orientation(p1, p2, p4);
	o3 = orientation(p3, p4, p1);
	o4 = orientation(p3, p4, p2);
	if(o1 != o2 && o3 != o4) {
		printf("Yes\n");
		return 0;
	}
	if(o1 == 0 && onseg(p1, p3, p2)) printf("Yes\n");
	else if(o2 == 0 && onseg(p1, p4, p2)) printf("Yes\n");
	else if(o3 == 0 && onseg(p3, p1, p4)) printf("Yes\n");
	else if(o4 == 0 && onseg(p3, p2, p4)) printf("Yes\n");
	else printf("No\n");
	return 0;
}