#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rg register
#define inf 0x7f7f7f7f
inline int read(){
	rg int ret=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
struct node{
	int v,idx,c;
	bool operator <(const node& x)const{
		return v<x.v;
	}
}now;
int n,m,a[55][405],top[55],sum;
bool fla,fini[55];
int k,ans[820005][2];
int lef[55],cnt,mp[55],mp2[55],dep[55][55];
int main(){
	//wtf????? ccf nmsl
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(); m=read();
	for(rg int i=1;i<=n;++i){
		for(rg int j=1;j<=m;++j){
			a[i][j]=read();
		}
		top[i]=m;
	}
	lef[++cnt]=m; mp[n+1]=1; mp2[1]=n+1;
	for(rg int g=1;g<=n;++g){
		memset(dep,0x7f,sizeof(dep));
		now=(node){inf,0,0};
		for(rg int i=1;i<=n+1;++i){
			if(top[i]==0||fini[i]) continue;
			fla=0; sum=0; 
			for(rg int j=1;j<=top[i];++j){
				dep[a[i][j]][i]=min(dep[a[i][j]][i],j);
				if(a[i][j]==a[i][1]&&fla==0) ++sum;
				else fla=1;
			}
			now=min(now,(node){top[i]-sum,i,a[i][1]});
		}
		int nol=now.v;
		while(nol){
			if(mp2[cnt]==now.idx) continue;
			int tmp=min(nol,lef[cnt]);
			nol-=tmp;
			lef[cnt]-=tmp;
			for(rg int i=1;i<=tmp;++i){
				ans[++k][0]=now.idx;
				ans[k][1]=mp2[cnt];
				a[mp2[cnt]][++top[mp2[cnt]]]=a[now.idx][top[now.idx]--];
			}
			if(lef[cnt]==0){
				--cnt; 
			}
		}
		for(rg int j=1;j<=n+1;++j){
			if(fini[j]||dep[now.c][j]==inf||j==now.idx) continue;
			while(top[j]>=dep[now.c][j]){
				if(a[j][top[j]]==now.c){
					ans[++k][0]=j;
					ans[k][1]=now.idx;
					a[now.idx][++top[now.idx]]=a[j][top[j]--];
				}else{
					ans[++k][0]=j;
					ans[k][1]=mp2[cnt]; --lef[cnt];
					a[mp2[cnt]][++top[mp2[cnt]]]=a[j][top[j]--];
					if(lef[cnt]==0){
						--cnt;
					}
				}
			}
			if(mp[j]<=cnt&&mp[j]!=0){
				lef[mp[j]]=m-dep[now.c][j]+1;
			}else{
				lef[++cnt]=m-dep[now.c][j]+1;
				mp[j]=cnt;
				mp2[cnt]=j;
			}
		}
		fini[now.idx]=1;
	}
	printf("%d\n",k);
	for(rg int i=1;i<=k;++i){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
