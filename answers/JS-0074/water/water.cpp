#include<cstdio>
#include<queue>
using namespace std;

#define _N 100001
#define int long long

int n,m;
int cnt[_N];
bool flag[_N];

struct Side
{
	int to;
	int next;
	Side()
	{
		to=next=0;
	}
	Side(int a,int b)
	{
		to=a;
		next=b;
	}	
};
Side sides[100000001];
int head[_N];
int cntsides;

void adde(int from,int to)
{
	sides[++cntsides]=Side(to,head[from]);
	head[from]=cntsides;
}

struct FS
{
	int x;
	int y;
	FS()
	{
		x=0;
		y=1;
	}	
	FS(int a,int b)
	{
		x=a;
		y=b;
	}
};

FS ans[_N];

int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}

FS jia(FS a,FS b)
{
	int x=a.x*b.y+a.y*b.x;
	int y=a.y*b.y;
	int d=gcd(x,y);
	x/=d;
	y/=d;
	return FS(x,y);
}

FS chu(FS a,int c)
{
	int x=a.x;
	int y=a.y*c;
	int d=gcd(x,y);
	x/=d;
	y/=d;
	return FS(x,y);
}

queue<int> q;
FS w[_N];
bool inq[_N];
int ts;

void bfs(int x)
{
	for(int i=m+1;i<=n;i++)
	{
		w[i]=FS(0,1);
	}
	q.push(x);
	inq[x]=1;
	while(!q.empty())
	{
		int a=q.front();
//		if(ts<=100)
//		{
//			ts++;
//			printf("%d\n",a);
//		}
		q.pop();
		inq[a]=0;
		FS flow=w[a];
		w[a]=FS(0,1);
		int next=head[a];
		while(next!=0)
		{
			int y=sides[next].to;
			if(!inq[y])
			{
				q.push(y);
				inq[y]=1;
			}
			w[y]=jia(w[y],chu(flow,cnt[a]));
			if(flag[y])
			{
				ans[y]=jia(ans[y],chu(flow,cnt[a]));
			}
			next=sides[next].next;
		}
	}
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int d;
		scanf("%lld",&d);
		if(!d)
		{
			flag[i]=1;
		}
		cnt[i]=d;
		for(int j=1;j<=d;j++)
		{
			int a;
			scanf("%lld",&a);
			adde(i,a);
		}
		if(i<=m)
		{
			w[i]=FS(1,1);
		}
	}
	for(int i=1;i<=m;i++)
	{
		bfs(i);
	}
	for(int i=m+1;i<=n;i++)
	{
		if(flag[i])
		{
			if(ans[i].y!=1)
			{
				printf("%lld %lld\n",ans[i].x,ans[i].y);
			}
			else
			{
				printf("%lld\n",ans[i].x);
			}
		}
	}
	
	return 0;
}
