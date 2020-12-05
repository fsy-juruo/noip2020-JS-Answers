#include <bits/stdc++.h>
using namespace std;
ifstream fin("walk.in");
ofstream fout("walk.out");
typedef long long ll;
const int K=18,N=1e5+8;
const int mod=1e9+7;
int n,k,w[K],c[N],d[N],mxw;
int add[K],amn[K],amx[K],mxlg,a[K],pos[K];
void init(){
	memset(add,0,sizeof(add));
	memset(amn,0,sizeof(amn));
	memset(amx,0,sizeof(amx));
	for(int i=1;i<=n;++i){
		add[c[i]]+=d[i];
		amn[c[i]]=min(amn[c[i]],add[c[i]]);
		amx[c[i]]=max(amx[c[i]],add[c[i]]);
	}
	for(int i=0;i<=20;++i){
		for(int j=1;j<=k;++j){
			if(add[j]*(1<<i)>w[j]||add[j]*(1<<i)<-w[j]){
				mxlg=i-1;
				break;
			}
		}
		if(mxlg) break;
	}
}
bool check(int t){
	for(int i=1;i<=k;++i){
		if(pos[i]+amn[i]<1) return 0;
		if(pos[i]+amx[i]>w[i]) return 0;
		if(pos[i]+add[i]*((1<<t)-1)+amn[i]<1) return 0;
		if(pos[i]+add[i]*((1<<t)-1)+amx[i]>w[i]) return 0;
	}
	return 1;
}
bool AllZero(){
	for(int i=1;i<=k;++i)
		if(add[i]) return 0;
	return 1;
}
ll Ans;
void dfs(int de){
	if(de>k){
		for(int i=1;i<=k;++i) pos[i]=a[i];
		ll ans=0;
		for(int i=mxlg;i>=0;--i){
			if(check(i)){
				for(int j=1;j<=k;++j) pos[j]+=add[j]*(1<<i);
				ans+=(1<<i)*n%mod;
			}
		}
		if(AllZero()&&ans){
			Ans=-1;
			return;
		}
		for(int i=1;i<=n;++i){
			if(pos[c[i]]+d[i]<1||pos[c[i]]+d[i]>w[c[i]]){
				if(Ans!=-1) Ans=(Ans+ans+i)%mod;
				return;
			}
			pos[c[i]]+=d[i];
		}
		return;
	}
	for(int i=1;i<=w[de];++i){
		a[de]=i;
		dfs(de+1);
	}
}
void solve(){
	init();
	dfs(1);
	fout<<Ans%mod<<'\n';
}
int main(){
	fin>>n>>k;
	for(int i=1;i<=k;++i)
		fin>>w[i],mxw=max(mxw,w[i]);
	for(int i=1;i<=n;++i)
		fin>>c[i]>>d[i];
	if(mxw<=10) solve(); 
	else fout<<"-1\n";
	return 0;
}
