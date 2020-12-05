#include<bits/stdc++.h>
#define int long long
#define N 500007
#define M 11
#define INF 0x7fffffff
#define mo 1000000007
using namespace std;
int c[N],d[N],pos[M],p[M],w[M],a[M],sum,ans,t,n,k;
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x*=f;
	return;
}
inline void dfs(int x){
	if(x==k+1){
		//int cnt=INF;
		for(int i=1;i<=k;i++)pos[i]=p[i];
		/*for(int i=1;i<=k;i++){
			if(a[i]<0)cnt=Min(cnt,(pos[i]-1)/(-a[i]));
			if(a[i]>0)cnt=Min(cnt,(w[i]-pos[i])/a[i]);
		}
		for(int i=1;i<=k;i++)pos[i]+=a[i]*cnt;
		ans+=cnt*sum;*/
		while(1){
		for(int i=1;i<=n;i++){
			if(pos[c[i]]+d[i]<1){
				ans+=pos[c[i]];
				ans%=mo;
				return;
			}
			if(pos[c[i]]+d[i]>w[c[i]]){
				ans+=w[c[i]]-pos[c[i]]+1;
				ans%=mo;
				return;
			}
			pos[c[i]]+=d[i];
			ans+=abs(d[i]);
			ans%=mo;
		}
		}
	}
	for(int i=1;i<=w[x];i++){
		p[x]=i;
		dfs(x+1);
	}
	return;
}
inline void init(){
	read(n);read(k);
	for(int i=1;i<=k;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		read(c[i]);read(d[i]);
		a[c[i]]+=d[i];
		sum+=abs(d[i]);
	}
	for(int i=1;i<=k;i++)if(a[i]!=0)t=1;
	return;
}
inline void work(){
	dfs(1);
	return;
}
inline void put(){
	if(t==0)cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return;
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	init();
	if(t)work();
	put();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

