#include<bits/stdc++.h>
#define ll long long
#define N 820001
#define rg register
#define m_p make_pair
using namespace std;
ll n,m,ans[N][2],v[N],c[N],tot[52],s[52][501];
inline ll read()
{
	ll sum=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return f*sum;
}
void write(ll sum)
{//cout<<sum<<' ';
	for (rg int i=1;i<=sum;i++)
	printf("%lld %lld\n",ans[0],ans[1]);
}
bool ok(int j)
{
	for (rg int i=1;i<=tot[j];i++)
	if (s[j][i]!=s[j][1]) return 0;
	return 1;
}
void dfs(ll sum,ll las1,ll las2,ll cnt)
{
	if (sum>100) return;//cout<<sum<<' ';
	if (cnt==n) {write(sum);exit(0);}
	for (rg int i=1;i<=n+1;i++)
	if (tot[i]&&!v[i])
	for (rg int j=1;j<=n+1;j++)
	if (j!=i&&tot[j]<m&&(i!=las2||j!=las1)&&!v[j])
	{
		ll k=s[i][tot[i]];cout<<i<<' '<<j<<endl;
		//res[j]--;res[i]++;
		tot[i]--;s[j][++tot[j]]=k;
		ans[sum+1][0]=i,ans[sum+1][1]=j;
		if (tot[j]==m&&ok(j)) cnt++,v[j]=1; 
		dfs(sum+1,i,j,cnt);
		if (tot[j]==m&&ok(j)) v[j]=0; 
		//res[j]++;res[i]--;
		s[i][++tot[i]]=k;tot[j]--;
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for (rg int i=1;i<=n;i++)
	for (rg int j=1;j<=m;j++)
	{
		ll x=read();
		s[i][++tot[i]]=x;
		//cout<<tot[i]<<' ';
	}
	cout<<0;
	//dfs(0,0,0,0);
	return 0;
}
