#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;char ch=getchar();
	   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	   while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	   return x*f;
}
int n,k,w[11],c[500010],d[500010],ans=0,z[11],z1[11],flag=1,maxn=-1;
int mod=1e9+7;
void dfs(int dep){
	int cnt,res,zzj;
	if(dep==k+1){
		cnt=1;
		res=1;
		zzj=0;
		for(int i=1;i<=k;i++){
			z[i]=z1[i];
		}
		while(1){
			if(cnt>n){
				cnt=1;
				zzj++;
			}
			z[c[cnt]]+=d[cnt];
			if(z[c[cnt]]>w[c[cnt]]||z[c[cnt]]<1){
				break;
			}
			cnt++;
			res++;
			if(zzj>maxn){
				flag=0;
				return ;
			}
		}
		ans+=res;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=w[dep];i++){
		z1[dep]=i;
		dfs(dep+1);
		if(flag==0){
			return ;
		}
	}
	return ;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++){
		w[i]=read();
		maxn=max(maxn,w[i]);
	}
/*	for(int i=1;i<=n;i++){
		c=read(),d=read();
		for(int j=1;j<=k;j++){
			z[i][j]=z[i-1][j];
		}
		z[i][c]+=d;
	}*/
	for(int i=1;i<=n;i++){
		c[i]=read(),d[i]=read();
	}
	dfs(1);
	if(flag==0){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}

