#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);++i)
#define D(i,r,l) for(int i=(r);i>=(l);--i)
#define FF(i,ST,ED,DEL) for(int i=(ST);i!=(ED);DEL)
#define MEM(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define N 1003
namespace Flandre_Scarlet
{
	int a[N][N],sz[N];
	int n,m;
	inline void Input()
	{
		scanf("%lld%lld",&n,&m);
		F(i,1,n) F(j,1,m) scanf("%lld",&a[i][j]),sz[i]=m;
	}
	
	vector<pii> op;
	bool trans(int x,int y)
	{
		if (sz[x]==0 or sz[y]==m)
		{
//			puts("NO!");
			return false;
		}
		op.push_back(make_pair(x,y));
		a[y][++sz[y]]=a[x][sz[x]];
		a[x][sz[x]]=0; --sz[x];
		return true;
	}
	void top(int n,int id,int col) // 3*m steps
	{
//		printf(" top id=%d col=%d\n",id,col);
		int nx=id+1; if (nx==n+1) nx=1;
		int cnt=0; F(i,1,m) if (a[id][i]==col) ++cnt;
		if (cnt==0) return;
//		puts("  part1");
		F(i,1,cnt) trans(nx,n+1);
//		puts("  part2");
		while(sz[id])
		{
			if (a[id][sz[id]]==col) trans(id,nx);
			else trans(id,n+1);
		}
//		puts("  part3");
		F(i,1,m-cnt) trans(n+1,id);
//		puts("  part4");
		F(i,1,cnt) trans(nx,id);
//		puts("  part5");
		F(i,1,cnt) trans(n+1,nx);
//		puts(" done");
	}
	void solve(int n) // n*(3*n*m+m)
	{
//		printf("solve n=%d\n",n);
		if (n==1) return;
		F(i,1,n) top(n,i,n);
//		puts("trans prefix");
		F(i,1,n) while(a[i][sz[i]]==n) trans(i,n+1);
		int p=1;
		while(sz[n])
		{
			while(sz[p]==m) ++p;
			trans(n,p);
		}
		
		solve(n-1);
	}
	inline void Solve()
	{
		solve(n);
		printf("%d\n",op.size());
		for(int i=0;i<op.size();++i)
		{
			printf("%d %d\n",op[i].first,op[i].second);
		}
	}

	inline void Main()
	{
		Input();
		Solve();
	}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	Flandre_Scarlet::Main();
	return 0;
}


