#include<bits/stdc++.h>
#define N 500005
#define mod 1000000007
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
/* int 够不够，要不要long long?
	数组开得够不够？
	*/ 
using namespace std;
template<typename T>
inline void in(T &x)
{
	x=0;
	char c=getchar();
	bool fu=0;
	while(c<'0'||c>'9'){if(c=='-')fu=1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x=fu?-x:x;
}
template<typename T>
inline T Abs(T x){return x<0?-x:x;}
template<typename T>
inline void chmax(T &x,T y){x=x>y?x:y;}
template<typename T>
inline void chmin(T &x,T y){x=x<y?x:y;}
int n,k,w[15],c[N],d[N],now[15];
vector<int> v[2];
namespace brute
{
	void work()
	{
		v[0].clear();
		v[0].pb(0);
		for(int i=0;i<k;++i)
		{
			v[1].clear();
			for(int j=0;j<v[0].size();++j)
			{
				int from=v[0][j];
				for(int z=0;z<w[i];++z)
				v[1].pb(from*3+z);
			}
			swap(v[0],v[1]);
		}
		int maxn=0,ans=0;
		for(int i=0;i<k;++i)
		maxn=maxn*3+(w[i]-1);
		for(int b=0;b<v[0].size();++b)
		{
			int tt=v[0][b];
			for(int j=0;;j=(j+1)%n)
			{
				int t=tt;
				for(int i=k-1;i>=0;--i)
				{
					now[i]=t%3;
					t/=3;
				}
				
				now[c[j]]+=d[j],++ans;
				if(now[c[j]]<0||now[c[j]]>=w[c[j]])break;
				tt=0;
				for(int i=0;i<k;++i)
				tt=tt*3+(now[i]);
			}
			if(ans>=10000000)
			{
				puts("-1");
				return;
			}
		}
		printf("%d\n",ans);
	}
}
inline void add(int &x,int y)
{
	x+=y;
	if(x>=mod)x-=mod;
}
int sum[5][105],mx[5],mn[5];
namespace brute2
{
	void work()
	{
		v[0].clear();
		v[0].pb(0);
		for(int i=0;i<k;++i)
		{
			v[1].clear();
			for(int j=0;j<v[0].size();++j)
			{
				int from=v[0][j];
				for(int z=0;z<w[i];++z)
				v[1].pb(from*10+z);
			}
			swap(v[0],v[1]);
		}
		memset(sum,0,sizeof(sum));
		int maxn=0,ans=0;
		
		for(int i=0;i<k;++i)
		maxn=10*maxn+(w[i]-1),mx[i]=numeric_limits<int>::min(),mn[i]=numeric_limits<int>::max();
		sum[c[0]][0]=d[0];
		for(int i=0;i<k;++i)
		chmax(mx[i],sum[i][0]),
		chmin(mn[i],sum[i][0]);
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<k;++j)
			{
//				cout<<mx[j]<<' '<<mn[j]<<endl;
				if(j==c[i])
				sum[c[i]][i]=sum[c[i]][i-1]+d[i];
				else sum[j][i]=sum[j][i-1];
				chmax(mx[j],sum[j][i]);
				chmin(mn[j],sum[j][i]);
			}
		}
		for(int b=0;b<v[0].size();++b)
		{
			int tt=v[0][b];
			while(1)
			{
				int t=tt;
				for(int i=k-1;i>=0;--i)
				{
					now[i]=t%10;
					t/=10;
				}
				bool flag=1;
				for(int i=0;i<k;++i)
				if(now[i]+mx[i]>=w[i]||now[i]+mn[i]<0)
				{
					flag=0;
					break;
				}
				if(!flag)break;
				for(int i=0;i<k;++i)
				now[i]+=sum[i][n-1];
				tt=0;
				for(int i=0;i<k;++i)
				tt=tt*10+(now[i]);
				add(ans,n);
			}
			for(int j=0;;j=(j+1)%n)
			{
				int t=tt;
				for(int i=k-1;i>=0;--i)
				{
					now[i]=t%10;
					t/=10;
				}
				
				now[c[j]]+=d[j],add(ans,1);
				if(now[c[j]]<0||now[c[j]]>=w[c[j]])break;
				tt=0;
				for(int i=0;i<k;++i)
				tt=tt*10+(now[i]);
			}
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	in(n);in(k);
	for(int i=0;i<k;++i)in(w[i]);
	for(int i=0;i<n;++i)in(c[i]),in(d[i]),--c[i];
	if(n<=5)
	{
		brute::work();
		return 0;
	}
	if(n<=100)
	{
		brute2::work();
		return 0;
	}
	puts("-1");
	return 0;
}
