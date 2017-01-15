#include <iostream>
#include <set>
#include <stdio.h>
#include <utility>
#define ff first
#define ss second
using namespace std;
int main() {
	int n, val1, val2;
	scanf("%d", &n);
	pair < int, int > p[n];
	for(int i = 0 ; i < n; i++)
		scanf("%d%d", &p[i].ff, &p[i].ss);
	set < pair < int, int > > s;
	for(int i = 0 ; i < n ; i++)
		s.insert(p[i]);
	set < pair < int, int > > :: iterator it;
	printf("Enter pair : ");
	cin >> val1 >> val2;
	it = s.lower_bound(make_pair(val1, val2));
	if(it != s.end())
		cout << it->ff << " " << it->ss << endl;
	else
		cout << "end" << endl;
	return 0;
}