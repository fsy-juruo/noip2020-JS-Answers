#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll in[100010],d[100010],edge[100010][5];
struct num{
	ll fz,fm;
	num(ll _fz,ll _fm){
		fz=_fz,fm=_fm;
	}
	num(){
		fz=0,fm=1;
	}
}sum[100010];
ll gcd(ll a,ll b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
num yf(num a){
	return num(a.fz/gcd(a.fm,a.fz),a.fm/gcd(a.fm,a.fz));
}
num add(num a,num b){
	return yf(num(a.fm*b.fz+a.fz*b.fm,a.fm*b.fm));
}
num mul(num a,num b){
	return yf(num(a.fz*b.fz,a.fm*b.fm));
}
queue<ll> q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",d+i);
		for(ll j=1;j<=d[i];j++){
			scanf("%lld",&edge[i][j]);
			in[edge[i][j]]++;
		}
	}
	for(ll i=1;i<=n;i++){
		if(in[i]==0)
			q.push(i),sum[i]=num(1,1);
		else
			sum[i]=num(0,1);
	}
	while(q.size()){
		ll from=q.front();
		if(d[from]==0){
			q.pop();
			continue;
		}
		for(ll i=1;i<=d[from];i++){
			ll to=edge[from][i];
			sum[to]=add(sum[to],mul(sum[from],num(1,d[from])));
			in[to]--;
			if(in[to]==0)q.push(to);
		}
		sum[from]=num(0,1);
		q.pop();
	}
	for(ll i=1;i<=n;i++)
		if(sum[i].fz!=0)
			printf("%lld %lld\n",sum[i].fz,sum[i].fm);
	return 0;
}

