#include<bits/stdc++.h>
using namespace std;
int f_read(void)
{
	char c;
	while(!('0'<=c&&c<='9'))
		c=getchar();
	int res=0,t=1;
	if(c=='-')
	{
		t=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
long long gcd(long long a,long long b)
{
	if(a<b)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return (a*b)/gcd(a,b);
}
pair<long long,long long> simp(pair<long long,long long> a)
{
	long long x=a.first,y=a.second,g;
	g=gcd(x,y);
	return make_pair(x/g,y/g);
}
pair<long long,long long> div(pair<long long,long long> a,long long b)
{
	a.second*=b;
	return simp(a);
}
pair<long long,long long> add(pair<long long,long long> a,pair<long long,long long> b)
{
	long long x=0ll,y=lcm(a.second,b.second);
	x+=((y/a.second)*a.first);
	x+=((y/b.second)*b.first);
	return simp(make_pair(x,y));
}
int n,m,d,t,len,x;
vector<int> v[100005];
queue<int> q;
pair<long long,long long> ans[100005],p;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=f_read(),m=f_read();
	for(int i=1;i<=n;i++)
	{
		d=f_read();
		for(int j=1;j<=d;j++)
			t=f_read(),v[i].push_back(t);
		ans[i].second=1ll;
	}
	for(int i=1;i<=m;i++)
		q.push(i),ans[i]=make_pair(1ll,1ll);
	while(!q.empty())
	{
		len=q.size();
		for(int i=1;i<=len;i++)
		{
			x=q.front();
			q.pop();
			if(((int)(v[x].size()))==0)
				continue;
			p=div(ans[x],((long long)(v[x].size())));
			ans[x]=make_pair(0,1);
			for(int j=0;j<v[x].size();j++)
				ans[v[x][j]]=add(ans[v[x][j]],p),q.push(v[x][j]);
		}
	}
	for(int i=1;i<=n;i++)
		if(v[i].size()==0)
			printf("%lld %lld\n",ans[i].first,ans[i].second);
	return 0;
}
