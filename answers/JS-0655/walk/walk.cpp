#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int maxn=5E5+5;
int n,k,a[maxn];
int b[maxn],c[maxn];
namespace solve1
{
	void main()
	{
		cout<<-1<<endl;
	}
}
namespace solve2
{
	int wait[55];
	int tmp[55];
	int ans=0;
	inline void check()
	{
		int tot=0;
		for(int i=0;i<k;++i)
			tmp[i]=wait[i];
		for(int i=0;;++i)
		{
			tmp[b[i%n]]+=c[i%n];
			++tot;
			for(int j=0;j<k;++j)
				if(tmp[j]==0||tmp[j]>a[j])
					goto end;
			if(tot>100000)
			{
				cout<<-1<<endl;
				exit(0);
			}
		}
		end:;
		ans+=tot;
	}
	void dfs(int s)
	{
		if(s==k)
		{
			check();
			return;
		}
		for(int i=1;i<=a[s];++i)
		{
			wait[s]=i;
			dfs(s+1);
		}
	}
	void main()
	{
		dfs(0);
		cout<<ans<<endl;
	}
}
inline void solve()
{
	if(n<=1000&&k<=5)
		solve2::main();
	else if(k==1)
		solve1::main();
	else
		cout<<-1<<endl;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<k;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
	{
		cin>>b[i]>>c[i];
		--b[i];
	}
	solve();
	return 0;
}

