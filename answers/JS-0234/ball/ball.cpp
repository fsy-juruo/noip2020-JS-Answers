#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll powmod(ll a,ll b,ll p){
	ll res=1;
	for(;b;b>>=1){
		if(b&1)res=res*a%p;
		a=a*a%p;
	}
	return res;
}
ll gcd(ll a,ll b){
	ll r;
	while(b>0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
ll n,m,a[60][410];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	cout<<(n+1)*n/2<<endl;
	for(int i=1;i<=n+1;i++){
		for(int j=i+1;j<=n+1;j++){
			cout<<i<<' '<<j<<endl;
		}
	}
	return 0;
}
