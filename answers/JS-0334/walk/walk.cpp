#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,k,ans,w[20],a[20],c[500010],d[500010];
map<pair<int,vector<int> >,int> mp,vis;
bool ok=true;

inline int getint()
{
	int r=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		r=r*10+ch-'0';
		ch=getchar();
	}
	return r*flag;
}

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline void dfs2(vector<int>& v,int x)
{
	if(vis[make_pair(x,v)]==2) return;
	if(vis[make_pair(x,v)]==1){
		ok=false;return;
	}
	vis[make_pair(x,v)]=1;
	v[c[x]-1]+=d[x];
	if(v[c[x]-1]<=0||v[c[x]-1]>w[c[x]]){
		v[c[x]-1]-=d[x];
		mp[make_pair(x,v)]=1;vis[make_pair(x,v)]=2;return;
	}
	else{
		dfs2(v,x%n+1);
		if(!ok) return;
		int val=mp[make_pair(x%n+1,v)];
		v[c[x]-1]-=d[x];
		mp[make_pair(x,v)]=val+1;
		vis[make_pair(x,v)]=2;
		return;
	}
}

inline void dfs(int lvl)
{
	if(lvl==k+1){
		vector<int> v;
		for(int i=1;i<=k;i++) v.push_back(a[i]);
		dfs2(v,1);
		if(!ok) return;
		add(ans,mp[make_pair(1,v)]);
	}
	for(int i=1;i<=w[lvl];i++){
		a[lvl]=i;
		dfs(lvl+1);
		a[lvl]=0;
	}
}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=getint();k=getint();
	for(int i=1;i<=k;i++) w[i]=getint();
	for(int i=1;i<=n;i++){
		c[i]=getint();d[i]=getint();
	}
	if(n<=100&&k<=5){
		dfs(1);
		if(!ok) printf("-1\n");
		else printf("%d\n",ans);
	}
	else printf("-1\n");
	return 0;
}
