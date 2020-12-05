#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,b[4][25],s[4];
vector<pair<int,int> > ans;

bool legal()
{
	int sum=0;
	for(int i=1;i<=n+1;i++)
		if(s[i]>0)
		{
			sum++;
			int sb=b[i][1];
			for(int j=2;j<=s[i];j++)
				if(b[i][j]!=sb)
					return 0;
		}
	return sum==n;
}

void dfs(int x)
{
	if(legal())
	{
		cout<<x<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first<<' '<<ans[i].second<<endl;
		exit(0);
	}
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n+1;j++)
			if(i!=j && s[i]>0 && s[j]<m)
			{
				b[j][++s[j]] = b[i][s[i]];
				b[i][s[i]] = 0;
				s[i]--;
				ans.push_back(make_pair(i,j));
				dfs(x+1);
				ans.pop_back();
				b[i][++s[i]] = b[j][s[j]];
				b[j][s[j]] = 0;
				s[j]--;
			}
}

signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	s[1] = s[2] = m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	dfs(0);
	
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
