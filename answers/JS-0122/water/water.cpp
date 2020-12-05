#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
int n,m;
ll d[N],rd[N];
vector<int>to[N];
ll GCD(ll x,ll y) {
	if (y==0)
		return x;
	else
		return GCD(y,x%y);
}
ll gcd(ll x,ll y) {
	if (x<y)
		swap(x,y);
	return GCD(x,y);
}
struct frac {
	ll p,q;
}a[N];
void pls(int x,int y,ll k) {
	a[y].q*=k;
	a[x].p=a[x].p*a[y].q+a[y].p*a[x].q;
	a[x].q=a[x].q*a[y].q;
	int tmp=gcd(a[x].p,a[x].q);
	a[x].p/=tmp;
	a[x].q/=tmp;
	a[y].q/=k;
}
queue<int>q;
void topo() {
	for (int i=1;i<=m;i++)
		q.push(i);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (int i=0;i<to[u].size();i++) {
			int v=to[u][i];
			pls(v,u,d[u]);
			rd[v]--;
			if (rd[v]==0)
				q.push(v);
		}
		if (d[u]!=0)
			a[u].p=0,a[u].q=1;
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int x;
	for (int i=1;i<=n;i++) {
		cin>>d[i];
		for (int j=1;j<=d[i];j++) {
			cin>>x;
			to[i].push_back(x);
			rd[x]++;
		}
	}
	for (int i=1;i<=m;i++)
		a[i].p=1,a[i].q=1;
	for (int i=m+1;i<=n;i++)
		a[i].p=0,a[i].q=1;
	topo();
	for (int i=1;i<=n;i++)
		if (a[i].p!=0)
			cout<<a[i].p<<' '<<a[i].q<<endl;
	return 0;
}
