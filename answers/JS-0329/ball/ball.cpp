#include<bits/stdc++.h>
#define R register
using namespace std;

int n,m,k,l;
vector <int> a[100000];
int cza[100000],czb[100000];
int t;

inline bool pd()
{
	bool f=false;
	for (R int i=1;i<=n+1;i++)
	{
		if (a[i].size()==0)
		continue;
		if (a[i].size()!=m)
		return false;
		for (R int j=1;j<m;j++)
		{
			if (a[i][j]!=a[i][j-1])
			return false;
		}
	}
	return true;
}

void dfs(int dep)
{
	if (pd()==true)
	{
		cout << dep << endl;
		for (R int i=1;i<dep;i++)
		{
			cout << cza[i] << ' ' << czb[i] << endl;
		}
		exit(0);
	}
	else
	{
		for (R int i=1;i<=n+1;i++)
		{
			for (R int j=1;j<=n+1;j++)
			{
				if (i==j) continue;
//				i->j
				t=rand();
				if (t%3==0) continue;
				if (a[i].size()!=0&&a[j].size()<m)
				{
					cza[dep]=i;czb[dep]=j;
					l=a[i][a[i].size()-1];
					a[i].pop_back();a[j].push_back(l);
					dfs(dep+1);
					a[i].push_back(l);a[j].pop_back();
				}
			}
		}
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	srand(time(0));
	for (R int i=1;i<=n;i++)
	{
		for (R int j=1;j<=m;j++)
		{
			cin >> k;
			a[i].push_back(k);
		}
	}
	dfs(1);
	return 0;
}

