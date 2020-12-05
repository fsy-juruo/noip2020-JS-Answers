#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
struct node1{
	int wz,gs;
};
long long n,m,c,y;
unsigned long long f,ff;
vector <long long> a[200000];
vector <long long> qd,zd;
vector <long long> ans[200000];
bool Hash[200000];
queue <node1> q;
node1 mm,nm;
void Work(long long st)
{
	while(!q.empty())
	q.pop();
	mm.gs=1;
	mm.wz=st;
	q.push(mm);
	while(!q.empty())
	{
		mm=q.front();
		q.pop();
		if(a[mm.wz].size()==0)
		{
			ans[mm.wz].push_back(mm.gs);
			continue;
		}
		for (int i=0;i<a[mm.wz].size();i++)
		{
			nm.gs=mm.gs*a[mm.wz].size();
			nm.wz=a[mm.wz][i];
			q.push(nm);
		}
	}
	return ;
}
long long gcd(long long aa,long long bb)
{
	if(bb==0)
	return aa;
	else return gcd(bb,aa%bb);
}
void yf(unsigned long long fz,unsigned long long fm)
{
	unsigned long long mini;
	mini=min(fz,fm);
	if(fz%fm==0)
	{
		cout<<fz/fm<<' '<<1<<endl;
		return ;
	}
	if(fm%fz==0)
	{
		cout<<1<<' '<<fm/fz<<endl;
		return;
	}
	for (long long i=2;i<=(int(sqrt(mini)));i++)
	{
		if(mini%i!=0)
		continue;
		while(fz%i==0&&fm%i==0)
		{
			fz/=i;
			fm/=i;
		}
		while(fz%(mini/i)==0&&fm%(mini/i)==0)
		{
			fz/=(mini/i);
			fm/=(mini/i);
		}
	}
	cout<<fz<<' '<<fm<<endl;
	return ;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&c);
		if(c==0)
		{
			zd.push_back(i);
		}
		else 
		{
			for (int j=1;j<=c;j++)
			{
				scanf("%lld",&y);
				Hash[y]=1;
				a[i].push_back(y);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if(Hash[i]==0)
		qd.push_back(i);
	}
	for (int i=0;i<qd.size();i++)
	{
		Work(qd[i]);
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=0;j<ans[i].size();j++)
//		{
//			cout<<ans[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for (int i=1;i<=n;i++)
	{
		if(ans[i].size()==0)
		continue;
		f=1;
		ff=0;
		f=ans[i][1];
		for (int j=1;j<ans[i].size();j++)
		{
			int llll;
			llll=gcd(f,ans[i][j]);
			f=f*ans[i][j]/llll;
		}
		for (int j=0;j<ans[i].size();j++)
		{
			ff+=(f/ans[i][j]);
		}
//		cout<<ff<<' '<<f<<endl;
		yf(ff,f);
	}
	return 0;
}
