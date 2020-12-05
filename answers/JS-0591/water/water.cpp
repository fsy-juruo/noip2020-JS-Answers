#include <bits/stdc++.h>
#define bug cout<<"bug "<<__LINE__<<endl
#define index xedni
#define int long long
using namespace std;
const int iuf=1e9+7;
const int MOD=1e9+7;
const int MAXN=100050;
struct fenshu
{
	int up;
	int down;
}a[MAXN];
int gcd(int a,int b)
{
	return !b?a:(gcd(b,a%b));
}
fenshu Add(fenshu a,fenshu b)
{
	fenshu c;
	c.down=a.down*b.down;
	c.up=a.down*b.up+a.up*b.down;
	if(c.up==0) return (fenshu){0ll,1ll};
	int G=gcd(c.up,c.down);
	c.up/=G;
	c.down/=G;
	return c;
}
fenshu Dvd(fenshu a,int b)
{
	fenshu c;
	c.up=a.up;
	c.down=a.down*b;
	if(c.up==0) return (fenshu){0ll,1ll};
	int G=gcd(c.up,c.down);
	c.up/=G;
	c.down/=G;
	return c;
}
int n,m,in[MAXN];
vector<int> g[MAXN];
vector<int> S;
vector<int> T;
struct node
{
	int pos;
	int in;
	bool operator <(const node &x) const
	{
		return in>x.in;
	}
};
priority_queue<node> q;
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int d; cin>>d;
		for(int j=1;j<=d;j++)
		{
			int tmp; cin>>tmp;
			g[i].push_back(tmp);
			in[tmp]++;
		}
		if(!d) T.push_back(i);
	}
	for(int i=1;i<=n;i++) if(!in[i]) a[i].up=1ll;
	for(int i=1;i<=n;i++) a[i].down=1ll;
	
//	for(int i=1;i<=n;i++) cout<<in[i]<<endl;
	
	for(int i=1;i<=n;i++) if(!in[i]) q.push((node){i,in[i]});
	while(!q.empty())
	{
		node fa=q.top(); q.pop();
		int u=fa.pos;
//		cout<<">"<<u<<endl;
		for(int i=0;i<(int)g[u].size();i++) in[g[u][i]]--;
		for(int i=0;i<(int)g[u].size();i++) a[g[u][i]]=Add(a[g[u][i]],Dvd(a[u],(int)g[u].size()));
		for(int i=0;i<(int)g[u].size();i++) if(!in[g[u][i]]) q.push((node){g[u][i],in[g[u][i]]});
	}
//	for(int i=1;i<=n;i++) cout<<a[i].up<<" "<<a[i].down<<endl;
	for(int i=0;i<(int)T.size();i++) cout<<a[T[i]].up<<" "<<a[T[i]].down<<endl;
	return 0;
}
