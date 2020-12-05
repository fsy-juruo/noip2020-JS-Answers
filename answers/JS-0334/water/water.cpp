#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,cnt[100010],deg[100010],v[100010][10];
ll val1[100010],val2[100010];

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

inline ll gcd(ll a,ll b)
{
	if(b==0ll) return a;
	return gcd(b,a%b);
}

inline void add(int x,ll a,ll b)
{
	ll g=gcd(a,b);a/=g;b/=g;
	ll l=val2[x]/gcd(val2[x],b)*b;
	val1[x]=val1[x]*(l/val2[x])+a*(l/b);
	val2[x]=l;
	ll gg=gcd(val1[x],val2[x]);
	val1[x]/=gg;val2[x]/=gg;
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=getint();m=getint();
	vector<int> ans;
	for(int i=1;i<=n;i++){
		int x;x=getint();
		if(x==0){
			ans.push_back(i);
		}
		else{
			for(int j=1;j<=x;j++){
				int u;u=getint();
				cnt[i]++;
				v[i][cnt[i]]=u;
				deg[u]++;
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=m;i++){
		val1[i]=val2[i]=1ll;
		q.push(i);
	}
	for(int i=m+1;i<=n;i++){
		val1[i]=0ll;val2[i]=1ll;
	}
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=1;i<=cnt[t];i++){
			add(v[t][i],val1[t],val2[t]*(ll)cnt[t]);
			deg[v[t][i]]--;
			if(deg[v[t][i]]==0){
				q.push(v[t][i]);
			}
		}
	}
	for(int i=0;i<ans.size();i++) printf("%lld %lld\n",val1[ans[i]],val2[ans[i]]);
	return 0;
}
