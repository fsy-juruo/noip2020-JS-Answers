#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAX_N=500005,MAX_M=11,MAX_W=1e6+5,INF=0x3f3f3f3f;
int n,m;
int A[MAX_M];
int C[MAX_N],D[MAX_N];
bool check()
{
	int pos[MAX_M]={};
	for(int i=1;i<=n;i++)
	{
		pos[C[i]]+=D[i];
		if(pos[C[i]]<1-A[C[i]] || pos[C[i]]>A[C[i]]-1)return false;
	}
	for(int i=1;i<=m;i++)if(pos[i])return false;
	return true;
}
namespace subtask_1
{
	int st[MAX_N];
	int P[MAX_N];
	int walk()
	{
	//	cout<<"st:";
	//	for(int i=1;i<=m;i++)cout<<st[i]<<" \n"[i==m];
		for(int i=1;i<=m;i++)P[i]=st[i];
		int p=1;
		while(true)
		{
			int cur=(p-1)%n+1;
			P[C[cur]]+=D[cur];
		//	cout<<p<<' '<<cur<<' '<<C[cur]<<' '<<A[cur]<<":";
		//	for(int i=1;i<=m;i++)cout<<P[i]<<" \n"[i==m];
			if(P[C[cur]]<1 || P[C[cur]]>A[C[cur]])return p;
			p++;
		}
	}
	int ans;
	void dfs(int v)
	{
		if(v==m+1)
		{
			ans+=walk();
			return;
		}
		for(int i=1;i<=A[v];i++)
		{
			st[v]=i;
			dfs(v+1);
		}
	}
	int main()
	{
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
}
namespace subtask_2
{
	typedef long long LL;
	const int MAX_N=500005,MAX_M=11,MAX_W=1000005,Mod=1e9+7;
	const LL INF=0x3f3f3f3f3f3f3f3fLL;
	int sum[MAX_M][MAX_N];
	int max_sum[MAX_M],min_sum[MAX_M];
	int lower[MAX_M][MAX_W]/*<=*/,upper[MAX_M][MAX_W]/*>=*/;
	LL can_walk[MAX_M][MAX_W];
	pair<LL,int> P[MAX_W*MAX_M];
	int add(int a,int b)
	{
		return a+b>=Mod?a+b-Mod:a+b;
	}
	int mul(int a,int b)
	{
		return 1LL*a*b%Mod;
	}
	int main()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sum[j][i]=sum[j][i-1];
			}
			sum[C[i]][i]+=D[i];
		}
		for(int i=1;i<=m;i++)
		{
			max_sum[i]=*max_element(sum[i]+1,sum[i]+n+1);
			min_sum[i]=*min_element(sum[i]+1,sum[i]+n+1);
		}
		memset(lower,0x3f,sizeof(lower));
		memset(upper,0x3f,sizeof(upper));
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=1;j--)
			{
				lower[i][sum[i][j]+MAX_N]=j;
				upper[i][sum[i][j]+MAX_N]=j;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int l=0,r=MAX_W-1;
			for(int j=r-1;j>=l;j--)upper[i][j]=min(upper[i][j],upper[i][j+1]);
			for(int j=l+1;j<=r;j++)lower[i][j]=min(lower[i][j],lower[i][j-1]);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=A[i];j++)
			{
				int l=1-min(min_sum[i],0),r=A[i]-max(0,max_sum[i]);
				int pt=j;
				if(pt>=l && pt<=r && sum[i][n]==0)
				{
					can_walk[i][j]=INF;
					continue;
				}
				if(pt>=l && pt<=r)
				{
					if(sum[i][n]>0)
					{
						int x=(r-pt)/sum[i][n];
						can_walk[i][j]+=(x+1)*n;
						pt+=(x+1)*sum[i][n];
					}
					else
					{
						int x=(pt-l)/(-sum[i][n]);
						can_walk[i][j]+=(x+1)*n;
						pt+=(x+1)*sum[i][n];
					}
				}
				int nxp=n+1;
				if(A[i]-pt+1<=max_sum[i])nxp=min(nxp,upper[i][MAX_N+A[i]-pt+1]);
				if(-pt>=min_sum[i])nxp=min(nxp,lower[i][MAX_N-pt]);
			//	int nxp=min(upper[i][MAX_N+A[i]-pt+1],lower[i][MAX_N-pt]);
				can_walk[i][j]+=nxp;
			}
		}
		int top=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=A[i];j++)
			{
				P[++top]=make_pair(can_walk[i][j],i);
			}
		}
		sort(P+1,P+top+1);
		int sum[MAX_M]={};
		int ans=0;
		for(int i=top;i>=1;i--)
		{
			int prod=1;
			for(int j=1;j<=m;j++)
			{
				if(j==P[i].second)continue;
				prod=mul(prod,sum[j]);
			}
			ans=add(ans,mul(P[i].first%Mod,prod));
			sum[P[i].second]++;
		}
		cout<<ans<<endl;
		return 0;
	}
	#undef int
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>A[i];
	for(int i=1;i<=n;i++)cin>>C[i]>>D[i];
	if(check())
	{
		cout<<-1<<endl;
		return 0;
	}
	subtask_2::main();
	return 0;
}
