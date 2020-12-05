#include<bits/stdc++.h>
using namespace std;
int mod=1000000007,k,t,n;
int a[20],w[20],c[500500],d[500500],maxn[20],minn[20],b[20],e[20];
long long ans,tim;
bool f,flag,pd;
int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
bool check(){
	for (int i=1;i<=k;i++){
		if (e[i]<=0 || e[i]>w[i]) return false;
	}
	return true;
}
void dfs(int x){
	if (flag==false) return;
	if (x>k){
		tim=0;
		for (int i=1;i<=k;i++) e[i]=a[i];
		f=true;
		pd=false;
		for (int i=1;i<=k;i++){
			if (b[i]!=0 || e[i]+maxn[i]>w[i] || e[i]+minn[i]<=0){
				pd=true;
				break;
			}
		}
		if (pd==false){
			flag=false;
			return;
		}
		while (f==true){
			f=true;
			for (int i=1;i<=k;i++){
				if (e[i]+maxn[i]>w[i] || e[i]+minn[i]<=0) f=false;
			}
			if (f==false) break;
			for (int i=1;i<=k;i++){
				e[i]+=b[i];
			}
			tim+=n;
			tim%=mod;
		}
		while (check()==true){
			tim++;
			t=tim%n;
			if (t==0) t=n;
			e[c[t]]+=d[t];
			tim%=mod;
		}
		ans+=tim;
		ans%=mod;
		return;
	}
	for (int i=1;i<=w[x];i++){
		a[x]=i;
		dfs(x+1);
		if (flag==false) return;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for (int i=1;i<=k;i++){
		w[i]=read();
	}
	for (int i=1;i<=n;i++){
		c[i]=read();d[i]=read();
		b[c[i]]+=d[i];
		maxn[c[i]]=max(maxn[c[i]],b[c[i]]);
		minn[c[i]]=min(minn[c[i]],b[c[i]]);
	}
	flag=true;
	dfs(1);
	if (flag==false){
		puts("-1");
	}
	else printf("%lld\n",ans%mod);
	return 0;
}
//npq RP++;

