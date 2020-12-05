#include <bits/stdc++.h>
#define bug cout<<"bug "<<__LINE__<<endl
#define index xedni
//#define int long long
using namespace std;
const int iuf=1e9+7;
const int MOD=1e9+7;
const int MAXN=15;
struct nod2
{
	int tmp[MAXN];
}his2[1000000];
int index2;
struct node
{
	int cur[MAXN];
}his[1000000];
int index;
int n,k,w[MAXN],c[MAXN],d[MAXN],can[MAXN];
int tmp[MAXN],ans;
bool Cando=1;
int Run()
{
	index=0;
	int cur[MAXN];
	for(int i=1;i<=k;i++) cur[i]=tmp[i];
	int id=0;
	int res=0;
//	cout<<">"; for(int i=1;i<=k;i++) cout<<tmp[i]<<" "; cout<<endl;
	while(1)
	{
		id++; if(id==n+1) id=1;
		res++;
		cur[c[id]]+=d[id];
		if(cur[c[id]]>w[c[id]] || cur[c[id]]<=0) break;
//		cout<<"  -"; for(int i=1;i<=k;i++) cout<<cur[i]<<" "; cout<<endl;
		if(id==1)
		{
			node son;
			for(int i=0;i<MAXN;i++) son.cur[i]=cur[i];
			bool found=0;
			for(int i=1;i<=index;i++)
			{
				bool sam=1;
				for(int j=1;j<=k;j++)
					if(his[i].cur[j]!=cur[j]) sam=0;
				if(sam) found=1;
			}
			if(found)
			{
				cout<<-1<<endl;
				exit(0);
			}
			index++;
			for(int i=1;i<=k;i++) his[index].cur[i]=cur[i];
		}
	}
	return res;
}
void Dfs(int u)
{
	if(u==k+1)
	{
		bool found=0;
		for(int i=1;i<=index2;i++)
		{
			bool sam=1;
			for(int j=1;j<=k;j++)
				if(his2[i].tmp[j]!=tmp[j]) sam=0;
			if(sam) found=1;
		}
		if(found) return ;
		index2++;
		for(int i=1;i<=k;i++) his2[index2].tmp[i]=tmp[i];
		
		int res=Run();
//		cout<<res<<endl;
		ans=(ans+res)%MOD;
		return ;
	}
	for(int i=1;i<=w[u];i++)
	{
		tmp[u]=i;
		Dfs(u+1);
	}
}
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++) cin>>w[i];
	for(int i=1;i<=n;i++) cin>>c[i]>>d[i];
	Dfs(1);
	cout<<ans<<endl;
	return 0;
}
