#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define MAXN 100005
int d[MAXN];
bool inq[MAXN];
vector<int> g[MAXN];
struct frac
{
	int fz,fm;
}f[MAXN];

inline int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}

inline frac yf(frac tmp)
{
	frac ans;
	if (tmp.fz==0) {
		ans.fz=0;
		ans.fm=1;
		return ans;
	}
	int g=gcd(tmp.fm,tmp.fz);
	ans.fm=tmp.fm/g;ans.fz=tmp.fz/g;
	return ans;
}

inline frac add(frac aa,frac bb)
{
	frac ans;
	ans.fm=aa.fm*bb.fm;
	ans.fz=aa.fm*bb.fz+aa.fz*bb.fm;
	return yf(ans);
}

inline frac div(frac aa,int divis)
{
	frac ans;
	ans.fm=divis*aa.fm;
	ans.fz=aa.fz;
//	cout<<ans.fm<<' '<<ans.fz<<endl;
	return yf(ans);
}

int n,m;
int q[3000005];int tail,head;
void bfs()
{
	frac zr;zr.fm=1;zr.fz=0;
	while (head<=tail)
	{
		int u=q[head];head++;
		inq[u]=false;
	//	cout<<u<<endl;
		if (d[u]==0) continue;
		frac ot=div(f[u],d[u]);
	//	cout<<ot.fz<<' '<<ot.fm<<endl;
		f[u]=zr;
		for (int i=0;i<d[u];i++)
		{
			int v=g[u][i];
		//	cout<<v<<endl;
			f[v]=add(f[v],ot);
		//	cout<<f[v].fz<<' '<<f[v].fm<<endl;
			if (!inq[v]) q[++tail]=v;
			inq[v]=true;
		}
	}
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int x;
	for (int i=1;i<=n;i++){
		cin>>d[i];
		for (int j=1;j<=d[i];j++) 
		{
			cin>>x;
			g[i].push_back(x);
		}
		f[i].fm=1;f[i].fz=0;
	}
	frac tmp;tmp.fz=1;tmp.fm=1;
	for (int i=1;i<=m;i++) 
	{
		f[i]=tmp;inq[i]=true;
	}
	tail=0;head=1;
	for (int i=1;i<=m;i++) q[++tail]=i;
	bfs();
	for (int i=1;i<=n;i++) if (d[i]==0) cout<<f[i].fz<<' '<<f[i].fm<<endl;
	return 0;
}

