#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;
#define ll long long
int n,m,in[MAXN],vis[MAXN];
vector <int> edge[MAXN];
queue <int> Q;
ll my_gcd(ll a,ll b)
{
	return b==0?a:my_gcd(b,a%b);
}
struct Node
{
	ll p;
	ll q;
}res[MAXN];
Node add(Node a,Node b)
{
	Node ans;
	ans.p=a.p*b.q+b.p*a.q;
	ans.q=a.q*b.q;
	ll ans_gcd=my_gcd(ans.p,ans.q);
	ans.p/=ans_gcd,ans.q/=ans_gcd;
	return ans;
}
void topo()
{
	while(!Q.empty())
	{
		int x=Q.front();
		vis[x]=1;
		Q.pop();
		int nxt_cnt=edge[x].size();
		if(nxt_cnt==0)
			continue;
		Node delta=res[x];
		delta.q*=nxt_cnt;
		for(int i=0;i<nxt_cnt;i++)
		{
			int y=edge[x][i];
			res[y]=add(res[y],delta);
			in[y]--;
			if(in[y]==0&&vis[y]==0)
				Q.push(y);
		}
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int cnt;
		cin>>cnt;
		for(int j=1;j<=cnt;j++)
		{
			int y;
			cin>>y;
			edge[i].push_back(y);
			in[y]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		res[i].q=1;
		if(i<=m)
		{
			res[i].p=1;
			Q.push(i);
		}
		else
			res[i].p=0;
	}
	topo();
	for(int i=1;i<=n;i++)
		if(edge[i].size()==0)
			cout<<res[i].p<<' '<<res[i].q<<endl;
	return 0;
}
