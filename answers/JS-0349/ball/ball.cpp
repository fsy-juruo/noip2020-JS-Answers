#include <bits/stdc++.h>
using namespace std;
int n,m,a[40][500];
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			scanf("%d",&a[i][j]);
		}
	}
	if(n==1) {
		for(int j=1;j<=m;++j) {
			cout<<a[1][j]<<" ";
		}
	}
}
