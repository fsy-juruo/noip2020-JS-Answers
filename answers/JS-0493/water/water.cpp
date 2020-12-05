#include <bits/stdc++.h>
using namespace std;
#define signed long long
const signed maxn=1e5+5;
int read()
{
	static int*tmp=new int();
	scanf("%d",tmp);
	return *tmp;
}
vector<signed>vt[maxn];
void addedge(signed u,signed v)
{
	vt[u].push_back(v);
}
pair<signed,signed>s[maxn];
pair<signed,signed>ans[maxn];
signed gcd(signed a,signed b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
pair<signed,signed>ad(pair<signed,signed>a,pair<signed,signed>b)
{
	signed p=gcd(a.second,b.second);
	p=b.second/p*a.second;
	signed f=a.first*(p/a.second)+b.first*(p/b.second);
	signed g=gcd(f,p);
	return make_pair(f/g,p/g);
}
pair<signed,signed>dv(pair<signed,signed>a,signed b)
{
	a.second*=b;
	signed g=gcd(a.first,a.second);
	return make_pair(a.first/g,a.second/g);
}
void fs(signed x,signed n)
{
	for(signed i=1;i<=n;++i)
	{
		s[i].first=0;
		s[i].second=1;
	}
	s[x].first=s[x].second=1;
	queue<signed>q;
	q.push(x);
	while(!q.empty())
	{
		signed t=q.front();
		q.pop();
		signed siz=vt[t].size();
		if(siz==0||s[t].first==0) continue;
		pair<signed,signed>tmp=dv(s[t],siz);
		s[t].first=0;
		s[t].second=1;
		for(vector<signed>::iterator it=vt[t].begin(),ed=vt[t].end();it!=ed;++it)
		{
			s[*it]=ad(s[*it],tmp);
			q.push(*it);
			if(vt[*it].empty())
			{
				ans[*it]=ad(ans[*it],s[*it]);
				s[*it].first=0;
			}
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	signed n,m;
	n=read();
	m=read();
	for(signed i=0;i<maxn;++i)
	{
		ans[i].second=1;
	}
	for(signed i=1;i<=n;++i)
	{
		signed d=read();
		for(signed j=0;j<d;++j)
		{
			addedge(i,read());
		}
	}
	for(signed i=1;i<=m;++i)
	{
		fs(i,n);
	}
	for(signed i=1;i<=n;++i)
	{
		if(vt[i].empty())
		{
			//cout<<"t "<<i<<endl;
			printf("%d %d\n",(int)ans[i].first,(int)ans[i].second);
		}
	}
	return 0;
}

