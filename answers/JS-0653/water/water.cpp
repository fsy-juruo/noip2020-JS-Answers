#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline int read() {
	int ret=0;
	char ch=getchar(),last=' ';
	while(!isdigit(ch)) {ch=getchar();last=ch;}
	while(isdigit(ch)) {ret=ret*10+ch-'0';ch=getchar();}
	if(last=='-') ret=-ret;
	return ret;
}
/*
ll ksm(ll p,ll q) {
	if(q==1) return p;
	ll ret=1;
	while(q>1) {
		if(q&1) {
			ret=ret*p;
			q--;
		} else {
			p=p*p;
			q/=2;
		}
	}
	return ret*p;
}
*/

int n,m;
int first[100005],nextedge[500005];
ll out[100005];
struct node{
	int to,fro;	
}a[100005];
struct w{
	ll up,down;
}water[100005],d[100005];

ll gcd(ll a,ll b) {
	if(a>b) swap(a,b);
	if(a==0) return b;
	return gcd(b%a,a);
}

w cal(w p,w q) {
	if(p.down==0) return q;
	if(q.down==0) return p;
	w ret;
	ll tmp=gcd(p.down,q.down);
	ret.down=p.down/tmp*q.down;
	ret.up=p.up*(ret.down/p.down)+q.up*(ret.down/q.down);
	ll tmp2=gcd(ret.up,ret.down);
	ret.up/=tmp2;
	ret.down/=tmp2;
	return ret;
}

queue <int> q;
void bfs(int st) {
	q.push(st);
	while(!q.empty()) {
		int u=q.front();
		//cout<<u<<endl;
		q.pop();
		w tt=water[u];
		//printf("%d %lld %lld\n",u,tt.up,tt.down);
		tt.down*=out[u];
		int flag=0;
		for(int i=first[u];i;i=nextedge[i]) {
			water[a[i].fro]=cal(water[a[i].fro],tt);
			flag=1;
			d[a[i].fro]=cal(d[a[i].fro],tt);
			q.push(a[i].fro);
		}
		if(flag) water[u].up=water[u].down=0;
	}
	return;
}

int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	int edge=1;
	for(int i=1;i<=n;i++) {
		out[i]=1LL*read();
		for(int j=1;j<=out[i];j++) {
			a[edge].to=i;
			a[edge].fro=read();
			nextedge[edge]=first[a[edge].to];
			first[a[edge].to]=edge;
			edge++;
		}
	}
	for(int i=1;i<=m;i++) {
		//memset(water,0,sizeof(water));
		water[i].up=1LL;
		water[i].down=1LL;
		//d[i].up=d[i].down=1LL;
		bfs(i);
	}
	for(int i=1;i<=n;i++) {
		ll dd=gcd(water[i].up,water[i].down);
		if(water[i].up) printf("%lld %lld\n",water[i].up/dd,water[i].down/dd);
	}
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
