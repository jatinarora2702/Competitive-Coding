#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
int compute(int at, int af, int bt, int bf, char op, int k){
	//cout << at << " " << af << " " << bt << " " << bf << " " << op << " " << k << endl;
	switch(op){
		case '&': //cout << "a1" << endl;
				if(k == 1)
					 return (at * bt);
				  else
				  	 return (((at+af) * (bt+bf)) - (at*bt));
				  break;
		case '|': //cout << "a2" << endl;
					if(k == 1)
					 return (((at+af) * (bt+bf)) - (af*bf));
				  else
				  	 return (af * bf);
				  break;
		case '^': //cout << "a3" << endl;
					if(k == 1)
					 return ((at * bf) + (af * bt));
				  else
				  	 return ((at * bt) + (af * bf));
	}
}
int main() {
	int n, **dpt, **dpf, maxt, maxf, v;
	char *sym, *op, r;
	printf("Enter the no. of boolean terms : ");
	scanf("%d", &n);
	sym = new char[n];
	op = new char[n-1];
	dpt = new int*[n];
	dpf = new int*[n];
	for(int i = 0 ; i < n ; i++){
		dpt[i] = new int[n];
		dpf[i] = new int[n];
	}
	printf("Enter the boolean terms array :\n");
	scanf("%s", sym);	
	printf("Enter the operator array :\n");
	scanf("%s", op);
	for(int i = 0 ; i < n ; i++){
		if(sym[i] == 'T'){
			dpt[i][i] = 1;
			dpf[i][i] = 0;
		}
		if(sym[i] == 'F'){
			dpt[i][i] = 0;
			dpf[i][i] = 1;
		}
	}
	for(int k = 1 ; k < n ; k++) {
		for(int i = 0 ; i < n-k ; i++) {
			int j = i+k;
			maxt = 0;
			maxf = 0;
			for(int p = i ; p < i+k ; p++){
				//cout << "op=" << op[p] << endl;
				v = compute(dpt[i][p], dpf[i][p], dpt[p+1][j], dpf[p+1][j], op[p], 1);
				maxt += v;
				v = compute(dpt[i][p], dpf[i][p], dpt[p+1][j], dpf[p+1][j], op[p], 0);
				maxf += v;
			}
			dpt[i][j] = maxt;
			dpf[i][j] = maxf;
		}
	}
	printf("Max. parenthesization possible for true output is : %d\n", dpt[0][n-1]);
	/*
	cout << "t=\n";
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << setw(2) << dpt[i][j] << " ";
		}
		cout << endl;
	}
	cout << "f=\n";
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << setw(2) << dpf[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}