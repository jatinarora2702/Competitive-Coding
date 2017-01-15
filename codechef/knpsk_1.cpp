#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;
bool cmp(int a, int b){
	return (a > b);
}
int main() {
	int n, w, **items, wt, ct, it[2], j1, j2;
	ulli *cost, recsum, c1, c2;
	scanf("%d", &n);
	items = new int*[2];
	for(int i = 0 ; i < 2 ; i++)
		items[i] = new int[n];
	w = it[0] = it[1] = 0;
	j1 = j2 = 0;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &wt, &ct);
		w += wt;
		wt--;
		items[wt][it[wt]] = ct;
		it[wt]++;
	}
	cost = new ulli[w+1];
	recsum = 0;
	sort(items[0], items[0]+it[0], cmp);
	sort(items[1], items[1]+it[1], cmp);
	// for(int i = 0 ; i < it[0] ; i++)
	// 	cout << items[0][i] << " ";
	// cout << endl;
	// for(int i = 0 ; i < it[1] ; i++)
	// 	cout << items[1][i] << " ";
	// cout << endl;
	j1 = j2 = 0;
	for(int i = 2 ; i <= w ; i+=2){
		c1 = c2 = 0;
		if(j2 < it[1])
			c2 = items[1][j2];
		if(j1 < it[0])
		{	
			c1 = items[0][j1];
			if(j1+1 < it[0])
				c1 += (ulli)items[0][j1+1];
		}
		if(c1 > c2){
			recsum += c1;
			cost[i] = recsum;
			if(j1 < it[0]){
				j1++;
				if(j1 < it[0])
					j1++;	
			}
		}
		else{
			recsum += c2;
			cost[i] = recsum;
			if(j2 < it[1])
				j2++;
		}
	}
	recsum = j1 = j2 = 0;
	if(j1 < it[0]){
		cost[1] = items[0][j1];
		recsum += cost[1];
		j1++;
	}
	for(int i = 3 ; i <= w ; i+=2){
		c1 = c2 = 0;
		if(j2 < it[1])
			c2 = items[1][j2];
		if(j1 < it[0])
		{	
			c1 = items[0][j1];
			if(j1+1 < it[0])
				c1 += (ulli)items[0][j1+1];
		}
		if(c1 > c2){
			recsum += c1;
			cost[i] = recsum;
			if(j1 < it[0]){
				j1++;
				if(j1 < it[0])
					j1++;	
			}
		}
		else{
			recsum += c2;
			cost[i] = recsum;
			if(j2 < it[1])
				j2++;
		}
	}
	for(int i = 1 ; i <= w ; i++){
		cout << cost[i] << " ";
	}
	return 0;
}