#include<bits/stdc++.h>
using namespace std;
int n,m,d,mp[100001];
struct hhh{
	long long fm,fz;
	int inn,xi;
	friend bool operator <(hhh a,hhh b)
	{
		return a.inn>b.inn;
	}
}s[100001];
vector<int> gd[100001];
priority_queue<hhh> kkl;
long long yf(long long a,long long b)
{
	if(a==0)
	return b;
	return yf(b%a,a);
}
int ad(long long z,long long mm,long long x)
{
	//cout<<x<<' '<<z<<' '<<mm<<' '<<s[x].fz<<' '<<s[x].fm<<endl;
	long long t=yf(z,mm);
	z/=t;
	mm/=t;
	s[x].fz=s[x].fz*mm+s[x].fm*z;
	s[x].fm*=mm;
	t=yf(s[x].fz,s[x].fm);
	s[x].fz/=t;
	s[x].fm/=t;
	//cout<<s[x].fz<<' '<<s[x].fm<<endl;
	return 0;
}
int doo()
{
	while(!kkl.empty())
	{
		hhh t=kkl.top();
		//cout<<t.inn<<endl;
		kkl.pop();
		if(mp[t.xi]==1)
		continue;
		int cd=gd[t.xi].size();
		for(int j=0;j<cd;j++)
		{
			ad(s[t.xi].fz,s[t.xi].fm*cd,gd[t.xi][j]);
			//cout<<t.xi<<' '<<s[t.xi].fz<<' '<<s[t.xi].fz*cd<<endl;
			s[gd[t.xi][j]].inn--;
			kkl.push(s[gd[t.xi][j]]);
		}
		mp[t.xi]=1;
	}
	return 0;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		s[i].xi=i;
		s[i].fm=1;
		s[i].fz=0;
		scanf("%d",&d);
		for(int j=0;j<d;j++)
		{
			int x;
			scanf("%d",&x);
			gd[i].push_back(x);
			s[x].inn++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		s[i].fz=1;
		kkl.push(s[i]);
	}
	//cout<<"LLL";
	doo();
	for(int i=1;i<=n;i++)
	{
		if(gd[i].size()==0)
		{
			//cout<<i;
			printf("%lld",s[i].fz);
			if(s[i].fm!=1)
			printf(" %lld",s[i].fm);
			printf("\n");
		}
	}
	return 0;
}
