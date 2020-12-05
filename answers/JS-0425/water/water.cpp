#include<bits/stdc++.h>
using namespace std;
#define maxn 100003
#define ll long long
#define inf 2147483647
struct fraction{
	int son,mother;
	void simplify(){
		if(son==0) {mother=1;return;}
		int gcd=__gcd(son,mother);
		son/=gcd;
		mother/=gcd;
	}
	fraction operator +(const fraction& d) const {
		fraction ans;
		int a=d.son,b=d.mother;
		int gcd=__gcd(mother,b);
		ans.mother=mother/gcd*b;
		ans.son=b/gcd*son+mother/gcd*a;
		ans.simplify();
		return ans;
	}
	fraction operator /(const int& d) const{
		fraction ans;
		ans.son=son;
		ans.mother=mother*d;
		ans.simplify();
		return ans;
	}
}flow[maxn];
fraction Make(int x,int y=1){fraction ans;ans.son=x,ans.mother=y;return ans;}
struct edge{
	int next,to,dis;
}e[maxn*2];
int n,m,d,x,tot,head[maxn],vis[maxn],cnt,ord[maxn],in[maxn],out[maxn];
void addedge(int x,int y) {e[++tot].next=head[x];head[x]=tot;e[tot].to=y;}
void dfs(int u){
	if(vis[u]!=0) return ; 
	vis[u]=1;
	for(int i=head[u];i>0;i=e[i].next){
		int v=e[i].to;
		if(vis[v]==0) dfs(v);
	}
	ord[cnt--]=u;
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		flow[i]=Make(0);
		scanf("%d",&out[i]);
		for(int j=1;j<=out[i];j++){
			scanf("%d",&x);
			addedge(i,x);
			in[x]++;
		}
	}
	cnt=n;
	for(int i=1;i<=n;i++) if(vis[i]==0 && in[i]==0) dfs(i);
	for(int i=1;i<=n;i++){
		int x=ord[i];
		if(in[x]==0)
			flow[x]=Make(1);
		if(out[x]==0) continue;
		fraction outflow=flow[x]/out[x];
		for(int j=head[x];j>0;j=e[j].next){
			int y=e[j].to;
			flow[y]=flow[y]+outflow;
		}
	}for(int i=1;i<=n;i++) if(out[i]==0) printf("%d %d\n",flow[i].son,flow[i].mother);
	return 0;
}
/*

data1

input:
5 1
3 2 3 5
2 4 5
2 5 4
0
0

output:
1 3
2 3

*/
