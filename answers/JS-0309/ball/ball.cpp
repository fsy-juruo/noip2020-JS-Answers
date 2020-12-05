#include<bits/stdc++.h>
#define N 55
#define M 405
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
int n,m,top;
int a[N][M],sz[N];
int stac[2][86005];
bool ok=0;
void dfs(int step,int lim)
{
//	cout<<"step:"<<step<<endl;
	bool done=1;
	int cnt0=0;
	for(int i=0;i<n+1;++i)
	{
		if(sz[i]!=0&&sz[i]!=m)
		{
			done=0;
			break;
		}
		if(sz[i]==0)
		{
			++cnt0;
			if(cnt0>1)
			{
				done=0;
				break;
			}
		}
		else if(sz[i]==m)
		{
			bool flag=1;
			for(int j=1;j<m;++j)
			if(a[i][j]!=a[i][j-1])
			{
				flag=0;
				break;
			}
			if(!flag)
			{
				done=0;
				break;
			}
		}
	}
	if(done)
	{
		ok=1;
		printf("%d\n",top);
		for(int i=0;i<top;++i)
		printf("%d %d\n",stac[0][i],stac[1][i]);
		return;
	}
	if(step==lim)return;
	for(int i=0;i<n+1;++i)
	if(sz[i]>0)
	{
		for(int j=0;j<n+1;++j)
		if(i!=j&&sz[j]<m)
		{
//			if(i+1==stac[1][top-1]&&j+1==stac[0][top-1])continue;
			stac[0][top]=i+1;stac[1][top]=j+1;
			++top;
			--sz[i];
			a[j][sz[j]++]=a[i][sz[i]];
			dfs(step+1,lim);
			if(ok)return;
			--sz[j];
			a[i][sz[i]++]=a[j][sz[j]];
			--top;
		}
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	in(n);in(m);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		in(a[i][j]);
		sz[i]=m;
	}
	for(int lim=100;lim<=86000;lim+=100)
	{
		dfs(0,lim);
		if(ok)return 0;
	}
	
	return 0;
}
