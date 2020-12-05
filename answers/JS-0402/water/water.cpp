#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define RE return
#define V vector
#define P pair
#define MP make_pair
#define PB push_back
using namespace std;
int readint(){
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int s=c-'0';c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+c-'0';
		c=getchar();
	}
	RE s;
}
void output(int x){
	if(x>=10)output(x/10);
	putchar((char)(x%10+'0'));
}
int n,m;
V<int> v[100005];
P<int,int> ans[100005];
int gcd(int x,int y){
	RE (!y)?x:gcd(y,x%y);
}
void solve(int &p,int &q){
	int t=gcd(p,q);
	p/=t;
	q/=t;
}
void add(P<int,int> &x,P<int,int> y){
	if(x.F==0){
		x=y;RE ;
	}
	P<int,int> now;
	now.S=x.S/gcd(x.S,y.S)*y.S;
	now.F=now.S/x.S*x.F+now.S/y.S*y.F;
	solve(now.F,now.S);
	x=now;
}
void dfs(int x,int p,int q){
	solve(p,q);
	add(ans[x],MP(p,q));
	int l=v[x].size();
	if(!l)RE;
	q=q*l;
	for(V<int>::iterator it=v[x].begin();it!=v[x].end();it++){
		dfs(*it,p,q);
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		int d;
		cin>>d;
		int x;
		FOR(j,1,d){
			cin>>x;
			v[i].PB(x);
		}
	}
	FOR(i,1,m)dfs(i,1,1);
	FOR(i,1,n){
		if(v[i].size()==0)cout<<ans[i].F<<' '<<ans[i].S<<'\n';
	}
	RE 0;
}

