#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define x0 xasdsajldk
#define x1 xklasjdklsa
#define y0 ysjaldksla
#define y1 yaklsdnwad
const int INF=0x3f3f3f3f,N=1e5+5,M=5e5+5;
int n,m;
int head[N],to[M],Next[M],cnt;
void add(int x,int y)
{
	Next[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
}
ll dp1[N],dp2[N];
ll gcd(ll x,ll y)
{
	while(y!=0)
	{
		x=x%y;
		swap(x,y);
	}
	return x;
}
ll chu[N];
int de[N];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		dp2[i]=1;
		int s;
		scanf("%d",&s);
		chu[i]=s;
		while(s--)
		{
			int x;
			scanf("%d",&x);
			add(i,x);
			de[x]++;
		}
	}
	queue<int> Q;
	for(i=1;i<=m;i++)
		dp1[i]=1;
	for(i=1;i<=n;i++)
	{
		if(!de[i]) Q.push(i);
	}
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		for(i=head[x];i;i=Next[i])
		{
			int u=to[i];
//			cout<<x<<" "<<u<<endl;
			ll p=dp1[x],q=dp2[x]*chu[x];
			ll b=dp1[u],a=dp2[u];
			ll s1=a*p+q*b;
			ll s2=a*q;
			if(s1==0)
			{
				s1=0;
				s2=1;
			}
			else
			{
				ll c=gcd(s1,s2);
				if(c!=0)
				{
					s1=s1/c;
					s2=s2/c;
				}				
			}
			dp1[u]=s1;
			dp2[u]=s2;
//			cout<<s1<<" "<<s2<<endl;
//			cout<<endl;
			de[u]--;
			if(!de[u])
			{
				Q.push(u);
			}
		}
	}

//	for(i=1;i<=n;i++)
//	{
//			printf("%lld %lld\n",dp1[i],dp2[i]);
//	}
//	cout<<endl;
	for(i=1;i<=n;i++)
	{
		if(!chu[i])
		{
			printf("%lld %lld\n",dp1[i],dp2[i]);
		}
	}
	return 0;
}
