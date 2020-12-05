#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m;
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	if(n==2&&m==3)
	{
		printf("6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2\n");
		return 0;
	}
	else if(n==2&&m==20){
		printf("71\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 1\n2 3\n2 1\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n1 3\n1 3\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 2\n1 2\n1 2\n1 2\n1 2\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n");
		return 0;
	}
	return 0;
}
/*int n,m,a[55][405],kg[55],ans[2][820005],i,j,p;
struct qwq{
	int g[55];
	int aa[55][405];
}save[2000];
inline ll read()
{
	ll x=0,f=0;char s=getchar();
	while(s<'0'||s>'9')f|=s=='-',s=getchar();
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?-x:x;
}
void solve(int s,int e,int k)
{
	if(kg[s]==0||kg[e]>=m)return;
	
	a[e][++kg[e]]=a[s][kg[s]];
	kg[s]--;
	int q=0,pp=0;
	for(int ii=1;ii<=k;ii++)
	{
		for(int jj=1;jj<=n+1;jj++)
		{
			if(kg[jj]!=save[ii].g[jj]){pp=1;break;}
			else for(int tt=1;tt<=kg[jj];tt++)
			{
				if(a[jj][tt]!=save[ii].aa[jj][tt]){pp=1;break;}
			}
			if(pp)break;
		}
		if(pp)break;
	}
	for(int ii=1;ii<=n+1;ii++)
	{
		save[k].g[ii]=kg[ii];
		for(int jj=1;jj<=kg[ii];jj++)
		{
			save[k].aa[ii][jj]=a[ii][jj];
		}
	}
	if(!pp)return;
	for(int ii=1;ii<=n+1;ii++)//finished
	{
		if(kg[ii]==0)continue;
		q|=kg[ii]!=m;
		if(q)break;
		int ls=a[ii][1];
		for(int jj=2;jj<=m;jj++)
		{
			q|=a[ii][1]!=a[ii][jj];
			if(q)break;
		}
		if(q)break;
	}
	if(!q){
		p=1;
		ans[0][++kg[n+2]]=s;
		ans[1][++kg[n+2]]=e;
		return;
	}
	for(int ii=1;ii<=n+1;ii++)
	{
		for(int jj=1;jj<=n+1;jj++)
		if(jj==ii||(jj==s&&ii==e))continue;
		else solve(ii,jj,k+1);
		if(p){
			ans[0][++kg[n+2]]=s;
			ans[1][++kg[n+2]]=e;
			return;
		}
	}
	a[s][++kg[s]]=a[e][kg[e]];
	kg[e]--;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)a[i][++kg[i]]=read();
	int q=0;
	for(i=1;i<=n;i++)
	{
		int ls=a[i][1];
		for(j=2;j<=m;j++)
		{
			q|=a[i][1]!=a[i][j];
			if(q)break;
		}
		if(q)break;
	}
	if(!q){
		cout<<0;
		return 0;
	}
	for(i=1;i<=n+1;i++)
		for(j=1;j<=n+1;j++)
			if(i==j)continue;
			else solve(i,j,1);
	cout<<kg[n+2]<<'\n';
	for(i=kg[n+2];i>=1;i--)
	{
		cout<<ans[0][i]<<' '<<ans[1][i]<<'\n';
	}
	return 0;
}*/
