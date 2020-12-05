#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n,m;

ull gcd(ull a,ull b)
{
	ull c=a%b;
	if(c==0) return b;
	return gcd(c,b-c);
}


struct water
{
	ull p,q;
	void print()
	{
		cout<<p<<" "<<q<<endl;
	}
};

water add(water x,water y)
{
	ull pp = x.p*y.q +y.p*x.q;
	ull qq = x.q*y.q;
	ull g = gcd(pp,qq);
	pp/=g;
	qq/=g;
	water res;
	res.p=pp;
	res.q=qq;
	return res;
	
}

water divide(water x,ull y)
{
	ull pp = x.p;
	ull qq = x.q*y;
	ull g = gcd(pp,qq);
	pp/=g;
	qq/=g;
	water res;
	res.p=pp;
	res.q=qq;
	return res;
	
}


bool watermap[10001][10001];
int d[10001];
bool out[10001];
bool in[10001];
water wate[10001];

void give(int node,water wa)
{
	bool fin = true;
	for(int i=1;i<=n;i++)
	{
		if(watermap[node][i]==1)
		{
			give(i,divide(wa,d[node]));
		}
	}
	if(fin==true)
	{
		wate[node]=add(wate[node],wa);
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	memset(out,1,sizeof(out));
	for(int i=1;i<=n;i++)
	{
		wate[i].q=1;
	}
	for(int i=1;i<=n;i++)
	{
		int di;
		cin>>di;
		d[i]=di;
		if(di==0)
		{
			in[i]=1;
		}
		for(int j=1;j<=di;j++)
		{
			int o;
			cin>>o;
			watermap[i][o]=1;
			out[o]=0;
		}
	}
	water water1;
	water1.p=1;
	water1.q=1;
	for(int i=1;i<=n;i++)
	{
		if(out[i])
		{
			give(i,water1);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(in[i])
		{
			wate[i].print();
		}
	}
	
	
	return 0;
}
