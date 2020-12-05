#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void input(ll &x)
{
	char c = getchar();
	ll y = 1;
	while(c<'0'||c>'9'){
		if(c=='-') y = -1;
		c = getchar();
	}
	x = 0;
	while(c>='0'&&c<='9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x = x * y;
}
struct node{
	ll son,mo;
	node(){
		
	}
	node(ll nson,ll nmo){
		son = nson;
		mo = nmo;
	}
}f[100001];
struct noip{
	ll v,son,mo;
	noip(){
		
	}
	noip(ll nv,ll nson,ll nmo){
		v = nv;
		son = nson;
		mo = nmo;
	}
};
vector<ll> e[500005];
ll ind[100001],oud[100001];
ll n,m;
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
queue<noip> q;
void bfs()
{
	while(!q.empty()){
		ll x = q.front().v,y = q.front().son,z = q.front().mo;
		q.pop();
		ll k = e[x].size();
		for(ll i=0;i<k;i++){
			ll now = e[x][i];
			if(f[now].mo==0){
				f[now].son = y ;
				f[now].mo = z * k;
			}
			else{
				ll uu = z * k;
				f[now].son =  f[now].son * uu + y * f[now].mo;
				f[now].mo *= uu;
			}
			ll num = gcd(f[now].son,f[now].mo);
			f[now].son /= num;
			f[now].mo /= num;
			q.push(noip(now,f[now].son,f[now].mo));
			if(oud[now]!=0){
				f[now].son = f[now].mo = 0;
			}
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	input(n);input(m);
	for(ll i=0;i<n;++i){
		ll d;
		input(d);
		f[i].son = f[i].mo = 0;
		for(ll j=0;j<d;j++){
			ll vv;
			input(vv);
			e[i].push_back(vv-1);
			ind[vv-1]++;
			oud[i]++;
		}
	}
	ll st;
	for(ll i=0;i<n;++i){
		if(ind[i]==0){
			st = i;
			f[i].son = f[i].mo = 1;
			q.push(noip(i,1,1));
		}
	}
	bfs();
	for(ll i=0;i<n;++i){
		if(oud[i]==0){
			ll num = gcd(f[i].son,f[i].mo);
			cout << f[i].son / num << " " << f[i].mo / num << endl;
		}
	}
	return 0;
}
