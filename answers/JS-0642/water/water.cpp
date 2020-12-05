#include<bits/stdc++.h>
#define ll long long
#define str string
#define dou double
#define ull unsigned long long
#define fi first
#define se second
using namespace std;

const int maxn=1e5+10;
int n,m;
int d[maxn],t;
vector<int> a[maxn];
int P[maxn],Q[maxn];
bool check[maxn];
int qwq[maxn];
int point;

int lcm(int x,int y)
{
	return x/__gcd(x,y)*y;
}

void add(int &x,int &y,int z,int w)
{
	if(x==0&&y==0)
	{
		x=z,y=w;
		return ;
	}
	int l=lcm(x,z);
	y*=l/x;
	w*=l/z;
	int ans=y+w;
	int gcd=__gcd(ans,l);
	x=l/gcd;
	y=ans/gcd;
}

void div(int x)
{
	int gcd=__gcd(d[x],P[x]);
	P[x]/=gcd;
	Q[x]*=d[x]/gcd;
}

void bfs()
{
	queue<int>que;
	for(int i=1;i<=m;i++)
	{
		que.push(i);
		check[i]=true;
		P[i]=1;
		Q[i]=1;
	}
	while(!que.empty())
	{
		int now=que.front();
		que.pop();
//		cout<<now<<endl;
		if(d[now]==0)
		{
//			cout<<"ok\n";
			continue;
		}
//		cout<<P[now]<<" "<<Q[now];
		div(now);
//		cout<<"yes\n";
		check[now]=false;
		for(int i=0;i<d[now];i++)
		{
			int to=a[now][i];
			add(Q[to],P[to],Q[now],P[now]);
			if(!check[to])
			{
				check[to]=true;
				que.push(to);
			}
		}
		P[now]=0;
		Q[now]=0;
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int q=1;q<=d[i];q++)
		{
			scanf("%d",&t);
			a[i].push_back(t);
		}
		if(d[i]==0)
		{
			qwq[++point]=i;
		}
	}
	bfs();
	for(int i=1;i<=point;i++)
	{
		printf("%d %d\n",P[qwq[i]],Q[qwq[i]]);
	}
	return 0;
}

