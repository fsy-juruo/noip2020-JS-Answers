#include <bits/stdc++.h>
using namespace std;
const int N=59;
const int M=409;
int n,m,ans;
int c[N][M];
int a=-1,b=-1;
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cin>>c[i][j];
			if (a==-1)
				a=c[i][j];
			if (a!=-1 && b==-1 && c[i][j]!=a)
				b=c[i][j];
		}
	}
	if (n==2) {
		ans=m*2;
		int ansd=0;
		for (int i=1;i<=m;i++)
			if (c[1][i]==a)
				ansd++;
		cout<<ans+ansd<<endl;
		for (int i=m;i>=1;i--) {
			if (c[1][i]==a)
				cout<<1<<' '<<2<<endl;
			else
				cout<<1<<' '<<3<<endl;
		}
		for (int i=1;i<=ansd;i++)
			cout<<2<<' '<<1<<endl;
		for (int i=m;i>=1;i--) {
			if (c[2][i]==a)
				cout<<2<<' '<<1<<endl;
			else
				cout<<2<<' '<<3<<endl;
		}
		return 0;
	}
	else
		cout<<0<<endl;
	return 0;
}
