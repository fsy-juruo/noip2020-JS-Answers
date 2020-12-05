#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct frc
{
	ull p,q;
	frc()
	{
		p=0;
		q=1;
	}
}in[100005];
ull gcd(ull a,ull b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
frc operator+(const frc &a,const frc &b)
{
	ull p=a.p*b.q+a.q*b.p;
	ull q=a.q*b.q;
	ull gc=gcd(p,q);
	frc c;
	c.p=p/gc;
	c.q=q/gc;
	return c;
}
inline frc div(frc a,ull x)
{
	ull gc=gcd(a.p,x);
	a.p/=gc;
	x/=gc;
	a.q*=x;
	return a;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0 
0
*/
vector<int> g[100005];
bool out[100005];
void watr(int x,frc f)
{
	//cout<<x+1<<" "<<f.p<<"/"<<f.q<<endl;
	in[x]=in[x]+f;
	for(int i=0;i<g[x].size();i++)
	{
		watr(g[x][i],div(f,g[x].size()));
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	n=read();m=read();
	for(int i=0;i<n;i++)
	{
		int di,ai;
		di=read();
		if(di==0) out[i]=1;
		else
		{
			for(int j=0;j<di;j++)
			{
				ai=read();
				g[i].pb(ai-1);
			}
		}
	}
	frc f;
	f.p=1;
	f.q=1;
	for(int i=0;i<m;i++)
	{
		watr(i,f);
	}
	for(int i=0;i<n;i++)
	{
		if(out[i])
		{
			cout<<in[i].p<<" "<<in[i].q<<endl;
		}
	}
	return 0;
}


