#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define pq priority_queue
#define ff first
#define ss second
#define isnum(c) (('0'<=c)&&(c<='9'))
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=60,MAXM=410,INF=2e9+7;
int s[MAXN][MAXM],top[MAXN],N,M;
vector<pii> ans;
inline void read(int &a)
{
	char c=getchar();
	bool f=0;
	a=0;
	while(!isnum(c))
	{
		f|=(c=='-');
		c=getchar();
	}
	while(isnum(c))
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return;
}
inline int find(int u,int n)
{
	int i;
	for(i=top[u];i>0;i--)
		if(s[u][i]==n)
			break;
	return i;
}
inline void move(int u,int v)
{
	int n=s[u][top[u]];
	top[u]--;
	top[v]++;
	s[v][top[v]]=n;
	ans.pb(mp(u,v));
	return;
}
inline void init()
{
	return;
}
inline void input()
{
	read(N);
	read(M);
	_for(i,1,N+1)
	{
		top[i]=M;
		_for(j,1,M+1)
			read(s[i][j]);
	}
	return;
}
inline void solve()
{
	int ext=0,free=N+1,cc;
	_for(tar,1,N)
	{
		_for(i,1,M)
			move(tar,free);
		cc=s[tar][top[tar]];
		_for(cur,tar+1,N+1)
		{
			while(find(cur,cc))
			{
				while(s[cur][top[cur]]!=cc)
					if(top[free]==M-1)
					{
						move(cur,tar);
						ext++;
					}
					else
						move(cur,free);
				move(cur,free);
				while(ext)
				{
					move(tar,cur);
					ext--;
				}
				move(free,tar);
			}
			while((top[cur]!=M)||(s[free][top[free]]==cc))
			{
				if(s[free][top[free]]==cc)
					move(free,tar);
				else
					move(free,cur);
			}
		}
	}
	return;
}
inline void print()
{
	cout<<ans.size()<<endl;
	_for(i,0,ans.size())
		printf("%d %d\n",ans[i].ff,ans[i].ss);
	return;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	init();
	input();
	solve();
	print();
	return 0;
}
