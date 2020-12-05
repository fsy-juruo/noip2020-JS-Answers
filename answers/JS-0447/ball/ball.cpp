#include <bits/stdc++.h>
using namespace std;
int a[11][1001];
int main (){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			cin >> a[i][j];
	int k;
	if (a[1][1]==1){
		for (k=2;k<=m;++k)
			if (a[1][k]!=1) break;
		for (int i=m;i>=k;--i)
			cout << "1 3" << endl;
		for (k=1;k<=m;++k)
			if (a[2][k]==1) cout << "2 1" << endl;
			else cout << "2 3" << endl;
	}
	else if (a[1][1]==2){
		for (k=2;k<=m;++k)
			if (a[1][k]!=2) break;
		for (int i=m;i>=k;--i)
			cout << "1 3" << endl;
		for (k=1;k<=m;++k)
			if (a[2][k]==2) cout << "2 1" << endl;
			else cout << "2 3" << endl;
	}
	return 0;
}

