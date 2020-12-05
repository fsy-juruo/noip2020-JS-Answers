#include<bits/stdc++.h>
#define LL long long 
using namespace std;

const int N=100005;
int n,m;
vector <int> g[N];
bool psk[N];
LL snum[N],ru[N];

struct fs
{
	LL fm,fz;
} wsl[N];

LL gcd(LL x,LL y)
{
	if(x<y) swap(x,y);
	if(y==0) return x;
	else return gcd(y,x%y);
}

fs fsxj(fs a,fs b)
{
	if(a.fm==0) return b;
	if(b.fm==0) return a;
	LL c=a.fm*b.fm/(gcd(a.fm,b.fm));
	fs ans;
	ans.fm=c;
	ans.fz=(c/a.fm)*a.fz+(c/b.fm)*b.fz;
	LL d=gcd(ans.fm,ans.fz);
	if(d==0) return ans; 
	ans.fm=ans.fm/d;
	ans.fz=ans.fz/d;
	return ans;
}

queue <int> q;

void topo()
{
	for(int i=1;i<=m;i++) q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<snum[x];i++)
		{
			int y=g[x][i];
			ru[y]--;
			fs delt;
			delt.fz=wsl[x].fz;
			delt.fm=wsl[x].fm*snum[x];
			wsl[y]=fsxj(wsl[y],delt);
			if(ru[y]==0) q.push(y);
		}
	}
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	memset(psk,0,sizeof(psk));
	for(int i=1;i<=n;i++)
	{
		if(i<=m)
		{
			wsl[i].fz=1;
			wsl[i].fm=1;
		}
		else
		{
			wsl[i].fz=0;
			wsl[i].fm=1;
		}
		int t;
		cin>>t;
		snum[i]=t;
		for(int j=1;j<=t;j++)
		{
			int x;
			cin>>x;
			ru[x]++;
			g[i].push_back(x);
		}
		if(t==0) psk[i]=1;
	}
	topo();
	for(int i=1;i<=n;i++)
		if(psk[i]) cout<<wsl[i].fz<<" "<<wsl[i].fm<<endl;
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/

