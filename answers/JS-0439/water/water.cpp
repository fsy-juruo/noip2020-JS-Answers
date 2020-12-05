#include <bits/stdc++.h>
using namespace std;
const int N=101000;
int ver[N],next[N],head[N],d[N],ansx[N],ansy[N],tot;
void add (int x,int y) {
	ver[++tot]=y;
	next[tot]=head[x],head[x]=tot;
}
void bfs (int x) {
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		x=q.front();q.pop();
		if (!d[x]) continue;
		ansy[x]*=d[x];
		for (int i=head[x];i;i=next[i]) {
			int y=ver[i];
			q.push(y);
			ansx[y]=ansx[y]*ansy[x]+ansx[x]*ansy[y];
			ansy[y]*=ansy[x];
		}
	}
}
int gcd (int x,int y) {
	if (y==0) return x;
	return gcd(y,x%y);
}
int main () {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,k,x;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		ansy[i]=1;
		cin>>k;
		for (int j=1;j<=k;j++) {
			cin>>x;
			add(i,x);
			d[i]++;
		}
	}
	for (int i=1;i<=m;i++) {
		ansx[i]=1;
		bfs(i);
	}
	for (int i=1;i<=n;i++) 
		if (!d[i]) {
			int k=gcd(ansx[i],ansy[i]);
			cout<<ansx[i]/k;
			if (ansy[i]/k!=1) cout<<' '<<ansy[i]/k;
			cout<<endl;
		}
	
	return 0;
}

