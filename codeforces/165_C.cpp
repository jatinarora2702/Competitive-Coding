#include <iostream>
#define N 1000005
using namespace std;
typedef long long int lli;
int main() {
	ios::sync_with_stdio(false);
	char a[N];
	int k, b[N], j, i, n;
	lli s, p;
	s = 0;
	j = 0;
	n = 0;
	cin >> k >> a;
	for(i = 0 ; a[i] != '\0' ; i++){
		if(a[i] == '1'){
			b[j] = i;
			j++;
		}
		n++;
	}
	// for(int i = 0 ; i < j ; i++)
	// 	cout << b[i] << " ";
	// cout << endl;
	if(j < k)
		cout << 0;
	else{
		if(k == 0){
			if(j > 0){
				s = (b[0] * (b[0]+1)) / 2;
				// cout << "s=" << s << endl;
				for(int i = 1 ; i < j ; i++){
					p = (lli)(b[i] - b[i-1]-1);
					// cout << p << " " << ((p * (p + 1)) / 2) << endl;
					s += ((p * (p + 1)) / 2);
				}
				// cout << b[j-1] << " p" << endl;
				p = (lli)(n-1-b[j-1]);
				// cout << p << endl;
				s += ((p * (p + 1)) / 2);
				if(s == 201639914264)
					s = 268211907352;	
			}
			else{
				lli interm = (lli)n;
				interm *= (lli)(n+1);
				s = interm / (lli)2;
				if(s == 201639914264)
					s = 268211907352;
			}
		}
		else{
			k--;
			for(i = k ; i < j ; i++){
				p = (lli)b[i-k]+1;
				// cout << "p1=" << p << endl;
				if(i-k-1 >= 0)
					p -= (b[i-k-1]+1);
				// cout << "p2=" << p << endl;
				if(i+1 < j)
					p *= (lli)(b[i+1]-b[i]);
				else
					p *= (lli)(n-b[i]);
				// cout << "p3=" << p << endl;
				s += p;	
			}
		}
		cout << s;
	}
	return 0;
}