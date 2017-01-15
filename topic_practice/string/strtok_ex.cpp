#include <bits/stdc++.h>
#define N 100000
using namespace std;
char str[N];
int main(){
	char *tok;
	char a[] = "word1 word2";
	fgets(str, sizeof(str), stdin);
	// tok = strtok(a, " ");
	// while(tok != NULL){
	// 	cout << tok;
	// 	tok = strtok(NULL, "&");
	// }
	tok = strtok(str, "&");
	while(tok != NULL){
		cout << "|" << tok << "|\n";
		tok = strtok(NULL, "&");
	}
	cout << str << endl;
	return 0;
}