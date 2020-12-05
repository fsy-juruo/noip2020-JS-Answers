#include<bits/stdc++.h>
using namespace std;
struct fenshu{
	long long fenzi,fenmu;
	fenshu make_fs(long long x,long long y)
	{
		fenshu t;
		t.fenzi=x;
		t.fenmu=y;
		return t;
	}
	long long gcd(long long x,long long y)
	{
		return (y)?gcd(y,x%y):x;
	}
	long long lcm(long long x,long long y)
	{
		return x/gcd(x,y)*y;
	}
	void yuefen()
	{
		long long t=gcd(fenzi,fenmu);
		fenzi/=t;
		fenmu/=t;
	}
	fenshu jia(fenshu b)
	{
		fenshu t;
		t.fenmu=lcm(fenmu,b.fenmu);
		t.fenzi=fenzi*(t.fenmu/fenmu)+b.fenzi*(t.fenmu/b.fenmu);
		t.yuefen();
		return t;
	}
	fenshu operator / (const int& b) const {
		fenshu t;
		t.fenzi=fenzi;
		t.fenmu=fenmu;
		t.fenmu*=b;
		t.yuefen();
		return t;
	}
};
vector<int>a[100010],zuizhong;
fenshu tiji[100010];
void dfs(int x)
{
//	printf("%d %d\n",(int)tiji[10].fenzi,(int)tiji[10].fenmu);
	if(tiji[x].fenzi==0||a[x].size()==0)return;
	fenshu t=tiji[x]/a[x].size();
	tiji[x].fenzi=0;
//	printf("%d %d %d\n",x,(int)t.fenzi,(int)t.fenmu);
	for(int i=0;i<(int)a[x].size();i++)
	{
		tiji[a[x][i]]=tiji[a[x][i]].jia(t);
		dfs(a[x][i]);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		if(i>m)
			tiji[i].fenzi=0;
		else
			tiji[i].fenzi=1;
		tiji[i].fenmu=1;
		int d;
		scanf("%d",&d);
		if(d==0)
			zuizhong.push_back(i);
		for(int j=1;j<=d;j++)
		{
			int t;
			scanf("%d",&t);
			a[i].push_back(t);
		}
	}
	for(int i=1;i<=m;i++)
	{
		dfs(i);
	}
	for(int i=0;i<(int)zuizhong.size();i++)
		cout<<tiji[zuizhong[i]].fenzi<<' '<<tiji[zuizhong[i]].fenmu<<endl;
	return 0;
}

