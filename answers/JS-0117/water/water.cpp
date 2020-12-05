#include<bits/stdc++.h>
using namespace std;
struct fs
{
	long long p,q;
	fs operator +(const fs x)
	{
		fs re;
		re.q=q*x.q;
		re.p=p*x.q+x.p*q;
		re.wh();
		return re;
	}
	fs operator *(const int x)
	{
		fs re;
		re.p=p;
		re.q=q*x;
		re.wh();
		return re;
	}
	void wh()
	{
		for(int i=2;i<=min(q,p)&&i*i<=max(q,p);++i)
		{
			while(q%i==0&&p%i==0)
			{
				q/=i;
				p/=i;
			}
		}
	}
}ans[100005];
vector<int> s; 
int dtop;
vector<int> r[100005];
vector<int> out;
map<int,int> into;
bool pd(int x)
{
	for(int i=0;i<out.size();++i)
	{
		if(x==out[i])
			return 1;
	}
	return 0;
}
bool cf(int x)
{
	for(int i=0;i<s.size();++i)
	{
		if(x==s[i])
			return 1;
	}
	return 0;
}
void dij(int t)
{
	int a;
	s.push_back(t);
	ans[t].p=1;
	ans[t].q=1;
	while(dtop<s.size())
	{
		a=s[dtop++];
		s[dtop-1]=-1;
		for(int i=0;i<r[a].size();++i)
		{
			if(!cf(r[a][i]))
				s.push_back(r[a][i]);
			if(ans[r[a][i]].q!=0)
				ans[r[a][i]]=ans[r[a][i]]+(ans[a]*r[a].size());
			else
			{
				ans[r[a][i]]=ans[a]*r[a].size();
			}
		}
		if(r[a].size()!=0)
			ans[a].p=ans[a].q=0;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,d,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		into[i]=i;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&d);
		for(int j=1;j<=d;++j)
		{
			scanf("%d",&x);
			r[i].push_back(x);
			into.erase(x);
		}
		if(r[i].size()==0)
		{
			out.push_back(i);
		}
	}
	for(int i=1;i<=into.size();++i)
	{
		int x=into[i];
		dij(x);
		s.clear();
		dtop=0;
	}
	for(int i=0;i<out.size();++i)
	{
		printf("%lld %lld\n",ans[out[i]].p,ans[out[i]].q);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
