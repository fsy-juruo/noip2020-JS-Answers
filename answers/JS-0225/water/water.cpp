#include<bits/stdc++.h>
#define ll long long 
using namespace std;
queue<ll>q;
ll a[100005],n,m,c,j,out,i,ans[2][100005];
struct mp{
	vector<ll>link;
	int lt,nt;
}g[100005];
inline ll read()
{
	ll x=0,f=0;char s=getchar();
	while(s<'0'||s>'9')f|=s=='-',s=getchar();
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?-x:x;
}
ll part(ll x,ll y)
{
	if(x==0||y==0)return max(x,y);
	ll t=max(x,y);
	y=min(x,y);
	x=t;
	if(y!=0)return part(y,x%y);
	else return y;
}
ll all(ll x,ll y)
{
	ll t=max(x,y),ct=1,ts=t;
	y=min(x,y);
	x=t;
	while(ts%y)ts=x*(++ct);
	return ts;
}
void solve()
{
	int id=q.front();q.pop();
	for(int ii=0;ii<=g[id].nt-1;ii++){
		int k=g[id].link[ii];
		g[k].lt--;
		if(g[k].lt==0&&g[k].nt!=0)
		q.push(k);
		
		ll mult=part(ans[1][id]*g[id].nt,ans[1][k]);
		ans[0][k]=ans[0][k]*(ans[1][id]*g[id].nt/mult);
		ll ls=ans[1][k];
		ans[1][k]=ans[1][k]*(ans[1][id]*g[id].nt/mult);
		ans[0][k]+=ans[0][id]*(ls/mult);
//		ans[1][k]+=ans[1][k]==0?g[id].nt:0;
		mult=part(ans[0][k],ans[1][k]);
		ans[0][k]/=mult;
		ans[1][k]/=mult;
		
	}
	if(!q.empty())solve();
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n;i++){
		c=read();g[i].nt=c;
		for(j=1;j<=c;j++){
			out=read();
			g[i].link.push_back(out),g[out].lt++;
		}
	}
	for(i=1;i<=n;i++)ans[1][i]=1;
	for(i=1;i<=n;i++)if(g[i].lt==0)ans[0][i]=1,q.push(i),g[i].lt=-1;
	solve();
	for(i=1;i<=n;i++)
	{
		if(g[i].nt==0)cout<<ans[0][i]<<' '<<ans[1][i]<<'\n';
	}
	return 0;
}
