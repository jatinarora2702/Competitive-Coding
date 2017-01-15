#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct{
	int wd, ht;
}env;
void merges(env *a, int *id1, int m, env *b, int *id2, int n, env *c, int *id3) {
	int i, j, k;
	i = j = k = 0;
	while(i < m and j < n){
		if(a[i].wd < b[j].wd){
			c[k] = a[i];
			id3[k] = id1[i];
			k++;i++;
		}
		else if(a[i].wd > b[j].wd){
			c[k] = b[j];
			id3[k] = id2[j];
			k++;j++;
		}
		else{
			if(a[i].ht <= b[j].ht) {
				c[k] = a[i];
				id3[k] = id1[i];
				k++;i++;
			}
			else{
				c[k] = b[j];
				id3[k] = id2[j];
				k++;j++;	
			} 
		}
	}
	while(i < m){
		c[k] = a[i];
		id3[k] = id1[i];
		i++;k++;	
	} 
	while(j < n) {
		c[k] = b[j];
		id3[k] = id2[j];
		k++;j++;
	}
}
int* mergesort(env *a, int n,int *idx){
	int *idx1 = new int[n];
	int *idx2 = new int[n];
	for(int i = 0 ; i < n ; i++)
		idx1[i] = idx[i];
	if(n == 0 or n ==1)
		return idx;
	int m = n/2;
	env *b = new env[n];
	idx = mergesort(a,m,idx);
	idx1 = mergesort(a+m,n-m,idx+m);
	merges(a,idx,m,a+m,idx1,n-m,b,idx2);
	for(int i = 0 ; i < n ; i++){
		a[i] = b[i]; 
	}
	return idx2;
}
int main() {
	int n, w, h, *dp, max, *s, *idx, *idx1;
	env *arr;
	max = 0;
	scanf("%d%d%d", &n, &w, &h);
	dp = new int[n];
	s = new int[n];
	arr = new env[n];
	idx = new int[n];
	idx1 = new int[n];
	for(int i = 0 ; i < n ; i++)
		idx[i] = i;
	for(int i = 0 ; i < n ; i++) {
		scanf("%d%d", &arr[i].wd, &arr[i].ht);
	}
	idx = mergesort(arr, n, idx);
	for(int i = 0 ; i < n ; i++){
		idx1[idx[i]] = i;
	}
	dp[n-1] = 1;
	s[n-1] = -1;
	for(int i = n-2 ; i >= 0 ; i--){
		dp[i] = 0;
		s[i] = -1;
		for(int j = i+1 ; j < n ; j++) {
			if(arr[i].wd < arr[j].wd){
				if(arr[i].ht < arr[j].ht){
					if(dp[i] < dp[j]){
						dp[i] = dp[j];
						s[i] = j;
					}
				}
			}
			else
				break;
		}
		dp[i]++;
	}
	for(int i = 0 ; i < n ; i++){
		if(w < arr[i].wd and h < arr[i].ht and dp[i] > dp[max])
			max = i;
	}
	printf("%d\n", dp[max]);
	while(max != -1){
		printf("%d ", idx1[max]+1);
		max = s[max];
	}
	return 0;
}