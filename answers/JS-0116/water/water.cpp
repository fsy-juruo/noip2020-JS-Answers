#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	register int s=0,f=1;
    register char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-f; ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
    return s*f;
}
const int N=100005;
vector <int> q[N];
vector <int> yz;
ll d[N],a[N],b[N];
bool h[N];
ll gcd(ll x,ll y) {
	ll r=x%y;
	while(r) x=y,y=r,r=x%y;
	return y;
}
void add(int dd,ll x,ll y) {
	if(a[dd]==0 && b[dd]==0) {
		a[dd]=x,b[dd]=y;
		return;
	}
	ll A=a[dd]*y+b[dd]*x;
	ll B=b[dd]*y;
	ll Gcd=gcd(A,B);
	A=A/Gcd,B=B/Gcd;
	a[dd]=A,b[dd]=B;
}
void dfs(int x) {
	if(h[x]==1) return;
	h[x]=1;
	for(int i=0;i<q[x].size();i++) {
		int nxt=q[x][i];
		dfs(nxt);
		ll A=a[nxt],B=b[nxt]*d[nxt];
	    ll Gcd=gcd(A,B);
	    A=A/Gcd,B=B/Gcd;
		add(x,A,B);
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++) {
		d[i]=read();
		if(d[i]==0) yz.push_back(i);
		for(int j=1;j<=d[i];j++) {
			int x=read();
			q[x].push_back(i);
		}
	}
	for(int i=1;i<=m;i++) a[i]=b[i]=1;
	for(int i=0;i<yz.size();i++) dfs(yz[i]);
    for(int i=0;i<yz.size();i++) cout<<a[yz[i]]<<" "<<b[yz[i]]<<"\n";
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
