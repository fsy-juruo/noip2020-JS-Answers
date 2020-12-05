#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL N=100001;
vector<LL> e[N];
LL now=0,out[N],in[N],put[N],watn[N],watd[N];
LL read(){
	LL x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
LL gcd(LL a,LL b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
LL lcm(LL a,LL b){
	return a*b/gcd(a,b);
}
void solve(LL p){
	if(out[p]==0) return;
	LL divn=watn[p],divd=watd[p]*out[p];
	LL x=gcd(divn,divd);
	divn/=x;
	divd/=x;
	for(LL i=0;i<out[p];i++){
		LL u=e[p][i];
		x=lcm(watd[u],divd);
		watn[u]=watn[u]*x/watd[u]+divn*x/divd;
		watd[u]=x;
		x=gcd(watn[u],watd[u]);
		watn[u]/=x;
		watd[u]/=x;
		in[u]--;
		if(in[u]==0) solve(u);
	}
}
int main(){
//	freopen("water3.in","r",stdin);
//	freopen("own.out","w",stdout);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	LL n,m;
	n=read(); m=read();
	for(LL i=1;i<=n;i++){
		watd[i]=1;
		out[i]=read();
		if(out[i]==0){
			now++;
			put[now]=i;
		}
		for(LL j=1;j<=out[i];j++){
			LL u=read();
			e[i].push_back(u);
			in[u]++;
		}
	}
	for(LL i=1;i<=m;i++){
		watn[i]=1;
		solve(i);
	}
	for(LL i=1;i<=now;i++){
		LL u=put[i];
		printf("%lld %lld\n",watn[u],watd[u]);
	}
	
	return 0;
}
