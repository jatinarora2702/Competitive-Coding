#include <stdio.h>
#include <iostream>
using namespace std;
int c[20];
int main()
{
	int n,l,r,x,i,j,sm,mx,mn,ans=0;
	scanf("%d%d%d%d",&n,&l,&r,&x);
	for (i=0;i<n;i++)
		scanf("%d",c+i);
	for (i=1;i<(1<<n);i++)
	{
		sm=0;
		mn=1000000000;
		mx=0;
		for (j=0;j<n;j++){
			cout << "i=" << i << " j=" << j << " 1<<j=" << (1<<j);
			if (i&(1<<j))
			{
				cout << " yes";
				sm+=c[j];
				if (c[j]>mx)
					mx=c[j];
				if (c[j]<mn)
					mn=c[j];
			}
			cout << endl;
		}
		cout << "done\n";
		if (sm>=l&&sm<=r&&mx-mn>=x)
			ans++;
	}
	printf("%d",ans);
	return 0;
}