#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
const int N=55;

int n,m;
stack<int> s[N];
int co[N];
vector<pii> ans;

bool check(stack<int> t)
{
	set<int> ss;
	while(!t.empty())
	{
		ss.insert(t.top());
		t.pop();
	}
	if(ss.size()==1 || ss.size()==0) return 1;
	return 0;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(0));
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int x; scanf("%d",&x);
		s[i].push(x);
	}
	int cnt=820000;
	while(cnt--)
	{
		int x=rand()%(n+1)+1;
		int y=rand()%(n+1)+1;
		while(s[x].empty() || s[y].size()==m)
		{
			x=rand()%(n+1)+1;
			y=rand()%(n+1)+1;
		}
		ans.pb(mp(x,y));
			int t=s[x].top();
			s[x].pop();
			if(s[y].empty()) co[y]=t;
			else if(t!=s[y].top()) co[y]=-1;
			s[y].push(t);
		int ok=0;
		for(int i=1;i<=n;i++)
		{
			if(check(s[i])) ok++;
			if(s[i].size()==0) ok+=1e8;
		}
		if(ok==n+1e8)
		{
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++)
				printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
	
	return 0;
}
