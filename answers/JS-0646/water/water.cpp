#include<bits/stdc++.h>
using namespace std;
int head[100010]={0},ver[100010]={0},Next[100010]={0},tot=0,rud[100010]={0},chud[100010]={0},n,m;
queue<int> q;
void add(int x,int y)
{
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
struct kkk
{
	long long zi;
	long long mu;
}dpm[100010]={0};
long long gcd(long long a,long long b)
{
	if(a<b)
    {
    	int sss=a;
    	a=b;
    	b=sss;
	}
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
kkk addx(kkk x,kkk y)
{
	long long bb=x.mu,cc=y.mu;
	x.mu*=cc;
	x.zi*=cc;
	y.mu*=bb;
	y.zi*=bb;
	kkk p;
	p.zi=x.zi+y.zi;
	p.mu=x.mu;                        
	long long l=gcd(p.mu,p.zi);
	p.zi/=l;
	p.mu/=l;
	return p;
}
int main()
{
	freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int y;
			cin>>y;
			add(i,y);
			rud[y]++;
			chud[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(rud[i]==0)
		{
			dpm[i].zi=1;
			q.push(i);
		}
		dpm[i].mu=1;
	}
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=Next[i])
		{
			int y=ver[i];
			kkk oo;
			oo.zi=dpm[x].zi;
			oo.mu=dpm[x].mu*chud[x];
			dpm[y]=addx(oo,dpm[y]);
			rud[y]--;
			if(rud[y]==0)
			q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(head[i]==0)
		cout<<dpm[i].zi<<" "<<dpm[i].mu<<endl;
	}
	return 0;
}
