#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
//#define int long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template<typename T> void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template<typename T> void writeln(T x){
	write(x);
	puts("");
}
int n,m;
int deg[100005],d[100005];
long long fp[100005],fq[100005];
vector<int> g[100005],topo;
inline long long gcd(long long a,long long b)
{
	return (b==0?a:gcd(b,a%b));
}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(register int i=1;i<=n;++i)
	{
		read(deg[i]);
		d[i]=deg[i];
		for(register int j=1;j<=deg[i];++j)
		{
			int a;
			read(a);
			g[a].push_back(i);
		}
	}
	queue<int> q;
	for(register int i=1;i<=n;++i)
		if(deg[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		topo.push_back(p);
		for(register int i=0;i<g[p].size();++i)
		{
			deg[g[p][i]]--;
			if(deg[g[p][i]]==0)
				q.push(g[p][i]);
		}
	}
	for(register int i=topo.size()-1;i>=0;i--)
	{
		if(g[topo[i]].size()==0)
			fp[topo[i]]=fq[topo[i]]=1;
		else
		{
			fp[topo[i]]=0;
			fq[topo[i]]=1;
			for(register int j=0;j<g[topo[i]].size();++j)
			{
				long long pp=fp[g[topo[i]][j]],qq=fq[g[topo[i]][j]];
				qq*=d[g[topo[i]][j]];
				int gc=gcd(pp,qq);
				pp/=gc;
				qq/=gc;
				long long lcm=fq[topo[i]]*qq/gcd(fq[topo[i]],qq);
				fp[topo[i]]=fp[topo[i]]*lcm/fq[topo[i]]+pp*lcm/qq;
				fq[topo[i]]=lcm;
				gc=gcd(fp[topo[i]],fq[topo[i]]);
				fp[topo[i]]/=gc;
				fq[topo[i]]/=gc;
			}
		}
	}
	for(register int i=1;i<=n;++i)
		if(!d[i])
		{
			write(fp[i]);putchar(' ');writeln(fq[i]);
		}
	return 0;
}

