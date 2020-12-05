#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,m;
int c[MAXN];
int v;
int t[MAXN];
bool b[MAXN];
int ts,s;
struct fen{
	long long mu,zi;
}f[MAXN];
vector<int> G[MAXN];

int z(int a,int b)
{
	if(a<b) swap(a,b);
	int y=a;
	while(a%b!=0)
	{
		a+=y;
	}
	return a;
}

int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

void add(int u,int mm)
{
	int mu=f[u].mu,zi=f[u].zi;
	if(zi==0&&mu==0)
	{
		zi=1;
		mu=mm;
		f[u].mu=mu,f[u].zi=zi;
		return ;
	}
	int gbs=z(mm,mu);
	int zz=gbs/mm;
	zi=zi*(gbs/mu),mu=gbs;
	zi+=zz;
	int k=gcd(zi,mu);
	mu/=k,zi/=k;
	f[u].mu=mu,f[u].zi=zi;
}

void work(int u,int mm)
{
	if(G[u].size()==0) 
	{
		add(u,mm);
	}
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(c[v]!=0)	work(v,mm*c[v]);
		else work(v,mm);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=c[i];j++)
		{
			cin>>v;
			G[i].push_back(v);
			b[v]=1;
		}
		if(c[i]==0)
		{
			ts++;
			t[ts]=i;			
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			work(i,c[i]);
		}
	}

	for(int i=1;i<=ts;i++)
	{
		cout<<f[t[i]].zi<<" "<<f[t[i]].mu<<endl;
	}

	return 0;
}

