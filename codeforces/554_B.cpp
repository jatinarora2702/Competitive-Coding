#include <bits/stdc++.h>
using namespace std;
int row[101], col[101], arr[101], n;
bool comp(int v1, int v2){
	if(col[v1] < col[v2])
		return true;
	return false;
}
char a[101][101];
int main(){
	int max, sum;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%s", a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		row[i] = col[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(a[i][j] == '1'){
				row[i]++;
				col[j]++;
			}
		}
	}
	// for(int i = 0 ; i < n ; i++)
	// 	cout << row[i] << " ";
	// cout << endl;
	for(int i =  0 ; i < n ; i++){
		arr[i] = i;
	}
	sort(arr, arr+n, comp);
	// for(int i = 0 ; i < n ; i++){
	// 	cout << col[i] << " ";
	// }
	// cout << endl;
	// for(int i = 0 ; i < n ; i++){
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	max = 0;
	for(int i = 0 ; i < n ; i++)
		if(row[i] == n)
			max++;
	// cout << "max=" << max << endl;
	for(int i = 0 ; i < n ; i++){
		if(col[arr[i]] <= n/2){
			for(int j = 0 ; j < n ; j++){
				row[j] += (a[j][arr[i]] == '0') ? 1 : -1;
			}
			sum = 0;
			for(int j = 0 ; j < n ; j++)
				if(row[j] == n)
					sum++;
			// cout << "sum=" << sum << endl;
			if(sum > max)
				max = sum;
		}
		else
			break;
	}
	printf("%d", max);
	return 0;
}