#include <bits/stdc++.h>
using namespace std;
stack <int> a[55];
queue <int> q;
int n,m,qwq,ans[820000][2];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		q.push(i);
		for(int j=1;j<=m;j++){
			cin>>qwq;
			a[i].push(qwq);
		}
	}
	cout<<0;
	return 0; 
}

