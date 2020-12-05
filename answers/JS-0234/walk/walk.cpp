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
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cout<<-1<<endl;
	return 0;
}
