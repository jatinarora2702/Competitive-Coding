#include <bits/stdc++.h>
using namespace std;
int check_if_palin(string s){
	int i, j;
	i = 0;
	j = s.length() - 1;
	while(i < j){
		if(s[i] != s[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}
int get_min(string s){
	if(s.length() <= 1)
		return 0;
	int n, f, v;
	n = 1 + get_min(s.substr(1));
	for(int i = 1 ; i < s.length() ; i++ ) {
		if(s[i] == s[0]){
			//cout << "sub1 : " << s.substr(0,i+1) << " : done" << endl;
			f = check_if_palin(s.substr(0,i+1));
			if(f == 1){
				//cout << "sub2 : " << s.substr(i+1) << " : hhahah" << endl;
				if(i == s.length())
					v = 0;
				else if(i != s.length())
					v = 1 + get_min(s.substr(i+1));
				if(v < n){
					n = v;
				}
			}
		}
	}
	return n;
}
int main() {
	string s;
	int n;
	printf("Enter the string to find the min. palindromic partition :\n");
	cin >> s;
	cout << s.substr(1);
	n = get_min(s);
	printf("Min. no. of palindromic partitions are : %d\n", n);
	return 0;
}