#include <bits/stdc++.h>
using namespace std;
int n,m;
bool f[52];
deque<int>q[52],q1[52];
struct node{
	int a,b;
};
vector<node>ans;
bool check()
{
	bool f2=0;
	for (int i=0;i<n;i++)
	{
		bool f1=0;
		if (q[i].size()!=m)
		{
			f2=1;
			continue;
		}
		for (int j=1;j<m;j++)
		{
			if (q[i][j]!=q[i][0])
			{
				f1=1;
				f2=1;
				break;
			}
		}
		if (!f1)
		f[i]=1;
	}
	if (f2)
	return false;
	return true;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		q1[i].clear();
		for (int j=0;j<m;j++)
		{
			int x;
			scanf("%d",&x);
			q1[i].push_front(x);
		}
	}
	q1[n].clear();
	while (1)
	{
		ans.clear();
		memset(f,0,sizeof(f));
		for (int i=0;i<n;i++)
		{
			q[i].clear();
			for (int j=0;j<m;j++)
			{
				q[i].push_back(q1[i][j]);
			}
		}
		q[n].clear();
		for (int i=0;i<820000;)
		{
			if (check())
			{
				cout<<ans.size()<<endl;
				for (int j=0;j<ans.size();j++)
				cout<<ans[j].a<<" "<<ans[j].b<<endl;
				return 0;
			}
			if (rand()%2==0&&q[n].size()!=0)
			{
				int t=rand()%n;
				while (q[t].size()==m||f[t]==1)
				t=rand()%n;
				q[t].push_front(q[n].front());
				q[n].pop_front();
				node nd;
				nd.a=n+1;
				nd.b=t+1;
				ans.push_back(nd);
				i++;
			}
			else if (q[n].size()<m)
			{
				int t=rand()%n;
				while (q[t].size()==0||f[t]==1)
				t=rand()%n;
				q[n].push_front(q[t].front());
				q[t].pop_front();
				node nd;
				nd.a=t+1;
				nd.b=n+1;
				ans.push_back(nd);
				i++;
			}
		}
	}
	return 0;
}
