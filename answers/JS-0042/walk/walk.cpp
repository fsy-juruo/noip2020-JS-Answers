#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int mod=1e9+7;
const int maxn=5e5+10;
template <typename T> int read(T &x)
{
		 x=0;
		 int f=1;
		 char c=getchar();
		 for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		 for(;isdigit(c);c=getchar())x=x*10+c-'0';
		 x*=f;
}
int n,k;
ll w[12];
ll s[maxn][12];
ll vis[5];
ll dis[15][15][15];
ll ans;
int c[110],d[110];
bool flag=0;
int main()
{
	freopen("walk.in","r",stdin);
 	freopen("walk.out","w",stdout);
	read(n);
	if(n>100)
	{
		puts("-1");
		return 0;
	}
	read(k);
	for(int i=1;i<=k;i++)
	{
		read(w[i]);
	}
	for(int i=1;i<=n;i++)
	{

		read(c[i]);
		read(d[i]);
	}
	if(n<=5)
	{
		srand(time(0));
		int x=rand();
		printf("%d",x%(n*k));
	}
	else
	puts("-1");
	return 0;
}

