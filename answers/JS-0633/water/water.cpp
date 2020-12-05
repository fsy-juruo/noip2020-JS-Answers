#include<bits/stdc++.h>
#define mkp make_pair
#define ms(a,x) memset(a,x,sizeof (a))
#define io_speed_up ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug cout<<"bug"<<"\n"
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define rrep(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;

const ll maxn=1e5+5;

ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
struct fenshu{
	ll a,b; //a/b;
	void yuefen(){
		if(a==0 || b==0) return;
		ll d=gcd(a,b);
		a/=d;
		b/=d;
	}
	fenshu operator + (const fenshu &obj) const{
		fenshu ans;
		ans.b=b*obj.b;
		ans.a=a*obj.b+b*obj.a;
		ans.yuefen();
		return ans;
	}
	fenshu operator * (const fenshu &obj) const{
		fenshu ans;
		ans.a=a*obj.a;
		ans.b=b*obj.b;
		ans.yuefen();
		return ans;
	}
	void output(){
		cout<<a<<" "<<b<<"\n";
	}
};

fenshu make_fenshu(ll x,ll y=1){
	fenshu tmp;
	tmp.a=x;
	tmp.b=y;
	return tmp;
}


ll n,m;
vector<ll> g[maxn];
fenshu val[maxn];
ll deg[maxn];

void topo(){
	queue<ll> q;
	rep(i,1,n){
		if(deg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		ll u=q.front(); q.pop();
		ll siz=g[u].size();
		for(ll i=0;i<siz;i++){
			ll v=g[u][i];
			val[v]=val[v]+val[u]*make_fenshu(1,siz);
			deg[v]--;
			if(deg[v]==0){
				q.push(v);
			}
		}
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	io_speed_up;
	cin>>n>>m;
	rep(u,1,n){
		ll z; cin>>z;
		while(z--){
			ll v; cin>>v;
			g[u].push_back(v);
			deg[v]++;
		}
	}
	
	rep(i,1,m){
		val[i].a=1;
		val[i].b=1;
	}
	rep(i,m+1,n){
		val[i].a=0;
		val[i].b=1;
	}
	topo();
	rep(i,1,n){
		if(g[i].empty()){
			val[i].output();
		}
	}
	
	return 0;
}
//remember to check:
//1.long long
//2.freopen
//3.array size
//4.big testdata
//5.file name
//6.file comparison
//7.mod

