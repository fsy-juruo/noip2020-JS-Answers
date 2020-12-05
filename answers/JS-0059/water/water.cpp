#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int tot,ver[N],Next[N],head[N],h[100010],hh[100010];
int ans[100010],anss[100010];
int n,m;
int read(){
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)) {
		if (ch=='-') f=-1,ch=getchar();
	}
	while (isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	}
	return x*f;
}
void add(int x,int y){
	tot++,ver[tot]=y,Next[tot]=head[x],head[x]=tot;
}
void dfs(int x,int nu){
	if (h[x]==-1){
		
		if (ans[x]!=0||anss[x]!=0)
		{
			int mx=max(nu,anss[x]),kk=mx;int k=1;
			while (1)
			{
				if (mx%anss[x]==0&&mx%nu==0) break;
				++k;mx=kk*k;
			}
			ans[x]=ans[x]*(mx/anss[x])+(mx/nu),anss[x]=mx;//cout<<mx<<' ';
			//cout<<'!';
			for (int i=trunc(sqrt(ans[x])); i>=1; i--)
			{
				if (ans[x]%i==0){
					int jj=ans[x]/i;//cout<<i<<' '<<jj<<' '<<ans[x]<<' '<<anss[x]<<endl;
					if (anss[x]%jj==0) anss[x]/=jj,ans[x]/=jj;//,cout<<'!'<<jj<<endl;
					if (anss[x]%i==0)  anss[x]/=i,ans[x]/=i;//,cout<<i<<endl;
				}
			}
			
		}
		else ans[x]=1,anss[x]=nu;
		
		
	//	cout<<'!'<<x<<' '<<nu<<' '<<ans[x]<<' '<<anss[x]<<endl;
	}
	for (int i=head[x]; i; i=Next[i])
	{
		int y=ver[i];
		dfs(y,nu*h[x]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	n=read(),m=read();
	for (int i=1; i<=n; i++)
	{
		int x,y;
		x=read();
		if (x){
			h[i]+=x;
			for (int j=1; j<=x; j++)
			  y=read(),add(i,y),++hh[y];
		}
		else h[i]=-1;
	}
	for (int i=1; i<=n; i++)
	{
		if (hh[i]==0){
			dfs(i,1);
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (h[i]==-1) printf("%d %d\n",ans[i],anss[i]);
	}
	return 0;
}
