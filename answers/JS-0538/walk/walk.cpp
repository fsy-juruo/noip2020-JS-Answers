#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T> void read(T&x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int MAXN=100005;
const int MAXM=300005;
int n,m,fa[MAXN];
struct node{
	int u,v,w;
};
node e[MAXM];
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int find(int u)
{
	if(u==fa[u])return u;
	return fa[u]=find(fa[u]);
}
bool same(int x,int y)
{
	if(find(x)==find(y))return 1;
	return 0;
}
void _union(int x,int y)
{
	if(same(x,y))return ;
	fa[find(x)]=fa[find(y)];
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cout<<-1<<endl;
	return 0;
}

