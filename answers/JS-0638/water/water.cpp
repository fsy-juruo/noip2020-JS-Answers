#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
}

typedef long long ll;

inline ll read() {
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
inline void write(ll x) {
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')

const ll SIZE=101000;
ll n,m;
struct Num {
	ll a,b;
	Num() {
		a=b=0;
	}
	Num(ll x,ll y) {
		a=x,b=y;
	}
};
Num add(Num x,Num y) {
	Num res;
	ll t=__gcd(x.b,y.b);
	x.a*=y.b/t;
	y.a*=x.b/t;
	res.a=x.a+y.a,res.b=x.b*y.b/t;
	t=__gcd(res.a,res.b);
	res.a/=t,res.b/=t;
	return res;
}
Num div(Num x,ll y) {
	x.b*=y;
	ll t=__gcd(x.a,x.b);
	x.a/=t,x.b/=t;
	return x;
}

Num ans[SIZE];

signed main() {
	fre();
	n=read(),m=read();
	for(ll i=1; i<=m; i++)ans[i]=Num(1,1);
	for(ll i=m+1; i<=n; i++)ans[i]=Num(0,1);
	for(ll i=1; i<=n; i++) {
		ll d=read();
		if(d==0) {
			writesp(ans[i].a);
			writeln(ans[i].b);
		} else {
			Num tmp=div(ans[i],d);
			while(d--) {
				ll a=read();
				ans[a]=add(ans[a],tmp);
			}
		}
	}
	return 0;
}
