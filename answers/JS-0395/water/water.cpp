#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long n,m,d[maxn],a[maxn][10],fm[maxn],fz[maxn];
long long addfm(long long fz1,long long fm1,long long fz2,long long fm2){
	if(!fm1) return fm2;
	if(!fm2) return fm1;
	return fm1*fm2;
}
long long addfz(long long fz1,long long fm1,long long fz2,long long fm2){
	if(!fm1) return fz2;
	if(!fm2) return fz1;
	return (fz1*fm2+fz2*fm1);
}
long long gcd(long long x,long long y){
	if(!y) return x;
	return gcd(y,x%y);
}
void dfs(long long x){
	//cout<<x<<endl;
	if(!d[x]) return;
	//cout<<x<<":"<<fz[x]<<" "<<fm[x]<<endl;
	for(long long i=1;i<=d[x];++i){
		long long v=a[x][i];
		long long now=fm[v];
		fm[v]=addfm(fz[v],fm[v],fz[x],fm[x]*d[x]);
		fz[v]=addfz(fz[v],now,fz[x],fm[x]*d[x]);
		long long sb=gcd(fm[v],fz[v]);
		fm[v]/=sb;
		fz[v]/=sb;
		//cout<<v<<":"<<fz[v]<<" "<<fm[v]<<endl;
		dfs(v);
	}
	fm[x]=fz[x]=0;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i){
		cin>>d[i];
		for(long long j=1;j<=d[i];++j) cin>>a[i][j];
	}
	//for(long long i=1;i<=m;++i) fz[i]=fm[i]=1;
	for(long long i=1;i<=m;++i){
		fz[i]=fm[i]=1;
		dfs(i);
		//cout<<"checkpoint"<<endl;
		for(long long j=1;j<=n;++j) if(d[j]) fm[j]=fz[j]=0;
	}
	
	for(long long i=1;i<=n;++i) if(!d[i]) cout<<fz[i]<<" "<<fm[i]<<endl;
	return 0;
}
