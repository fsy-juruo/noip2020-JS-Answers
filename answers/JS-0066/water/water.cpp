#include<bits/stdc++.h>
using namespace std;
#define ll long long
int readint()
{
	char c=getchar(); int neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
ll readll()
{
	char c=getchar(); ll neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
void writeint(int x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[15]; int top=0;
	while(x) {int nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void writell(ll x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[25]; int top=0;
	while(x) {ll nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void Writeint(int x,char c)
{
	writeint(x); putchar(c); return;
}
void Writell(ll x,char c)
{
	writell(x); putchar(c); return;
}
const int maxn=1e5+5;
const int maxe=5e5+5;
const double eps=1e-12;
int head[maxn],to[maxe],nxt[maxe],tot,indeg[maxn],outdeg[maxn];
void add_edge(int u,int v)
{
	to[++tot]=v; nxt[tot]=head[u]; head[u]=tot; return;
}
pair<double,double> ans[maxn];
double GCD(double u,double v)
{
	if(fabs(u-0.0)<eps) return v;
	int q=(int)(v/u);
	return GCD(v-u*(double)q,u);
}
void add(int id,pair<double,double> val)
{
	pair<double,double> nxt=make_pair(ans[id].first*val.second+ans[id].second*val.first,ans[id].second*val.second);
	double com=GCD(nxt.first,nxt.second);
	ans[id].first=nxt.first/com;
	ans[id].second=nxt.second/com;
	return;
}
void solve(int root,double cur)
{
	for(int i=head[root];i;i=nxt[i])
		solve(to[i],cur*(double)outdeg[root]);
	if(outdeg[root]==0) add(root,make_pair((double)1,cur));
	return;
}
void fl()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
}
int main()
{
//	printf("%.24lf\n",(sizeof(ans)+sizeof(eps)+sizeof(head)+sizeof(indeg)+sizeof(maxe)+sizeof(maxn)+sizeof(nxt)+sizeof(outdeg)+sizeof(to)+sizeof(tot))/1024.0/1024.0);
	fl();
	int n=readint(),m=readint();
	for(int i=1;i<=n;i++)
	{
		outdeg[i]=readint();
		for(int j=1;j<=outdeg[i];j++)
		{
			int u=readint();
			indeg[u]++;
			add_edge(i,u);
		}
	}
	for(int i=1;i<=n;i++)
		ans[i].second=1.0;
	for(int i=1;i<=n;i++)
		if(indeg[i]==0)
		{
			solve(i,(double)1);
			m--;
		}
	for(int i=1;i<=n;i++)
		if(outdeg[i]==0)
			printf("%.0lf %.0lf\n",ans[i].first,ans[i].second);
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0

10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0

*/

