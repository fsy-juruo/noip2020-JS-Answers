#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rud[100010],chd[100010],n,m,st[100010][10];
ll p[100010],q[100010];
queue<int> qu;
int gcd(ll a,ll b)
{
	ll r=a%b;
	if (r==0)return b;
	else gcd(b,r);
}
void addd(ll p1,ll q1,ll p2,ll q2,int num)
{
	ll fenm=q1*q2/gcd(q1,q2);
	p1=fenm/q1*p1;p2=fenm/q2*p2;
	q1=fenm;q2=fenm;
	ll fens=p1+p2;
	ll GAN=gcd(fens,fenm);
	fens/=GAN;fenm/=GAN;
	p[num]=fens;q[num]=fenm;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>chd[i];
		for (int j=1;j<=chd[i];j++)
		{
			int x;
			cin>>x;
			rud[x]++;
			st[i][j]=x;
		}
		q[i]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (rud[i]==0)
		{
			qu.push(i);
			q[i]=1;p[i]=1;
		}
	}
	while (!qu.empty())
	{
		int i=qu.front();
		qu.pop();
		if (chd[i]==0)continue;
		ll ad=q[i]*chd[i];
		for (int j=1;j<=chd[i];j++)
		{
			int tar=st[i][j];
			addd(p[i],ad,p[tar],q[tar],tar);
			rud[tar]--;
			if (rud[tar]==0)qu.push(tar);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (chd[i]==0)
		{
			cout<<p[i]<<' '<<q[i]<<endl;
		}
	}
	return 0;
}
