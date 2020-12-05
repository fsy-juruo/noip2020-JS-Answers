#include<bits/stdc++.h>
using namespace std;
int w[15];
int c[100005],d[100005];
int mxm[15],mnm[15],edp[15];
int pos[15],now[15];
int n,k,ans=0,flag=1,ret=0;
const int mod=1e9+7;
bool check(){
	for(int i=1;i<=k;i++)if(now[i]+mxm[i]>w[i] || now[i]+mnm[i]<1)return false;
	return true;
}
void dfs(int p){
	if(ret)return;
	if(p==k){
		for(int i=1;i<=k;i++)now[i]=pos[i];
		int awa=0;
		while(check()){
			if(flag){
				ret=1;
				return;
			}
			for(int i=1;i<=k;i++)now[i]+=edp[i];
			awa=(awa+n)%mod;
		}
		for(int i=1;i<=n;i++){
			now[c[i]]+=d[i];
			awa++;
			if(awa==mod)awa=0; 
			if(now[c[i]]<1 || now[c[i]]>w[c[i]])break;
		}
		ans=(ans+awa)%mod;
		return;
	}
	for(int i=1;i<=w[p+1];i++){
		pos[p+1]=i;
		dfs(p+1);
		if(ret)return;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout); 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++)scanf("%d%d",c+i,d+i);
	for(int i=1;i<=n;i++){
		edp[c[i]]+=d[i];
		mxm[c[i]]=max(mxm[c[i]],edp[c[i]]);
		mnm[c[i]]=min(mnm[c[i]],edp[c[i]]);
	}
	for(int i=1;i<=k;i++)if(edp[i]!=0)flag=0;
	dfs(0);
	if(ret)printf("-1");
	else printf("%d",ans);
	return 0;
}
