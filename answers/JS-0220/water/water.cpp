#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
struct node{
	int to;
	int next;
}e[100005];
struct fs{
	ll fm;
	ll fz;
}ans[100005];
int head[100005];
int cnt;
ll d[100005];
int n,m,x,cnt2;
queue<int>q;
bool vis[100005];
bool final[100005];
void adde(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
ll gcd(ll x,ll y){
	if(y==0)return x;
	return gcd(y,x%y);
}
fs fsplus(ll i1,ll i2,ll j,ll k){
	ll fzi=i1*k+j*i2;
	ll fmu=i2*k;
	ll r=gcd(fzi,fmu);
	fzi/=r;
	fmu/=r;
	fs t;
	t.fm=fmu;
	t.fz=fzi;
	return t;
}
void dfs(int k){
	vis[k]=1;
	if(final[k])return;
	for(int i=head[k];i;i=e[i].next){
		int t=e[i].to;
		ans[t]=fsplus(ans[t].fz,ans[t].fm,ans[k].fz,ans[k].fm*d[k]);
		dfs(t);
	}
}
void bfs(int k){
	q.push(k);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].next){
			int t=e[i].to;
			ans[t]=fsplus(ans[t].fz,ans[t].fm,ans[x].fz,ans[x].fm*d[x]);
			if(!vis[t]){
				q.push(t);
				vis[t]=1;
			}
		}
	}
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' ||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i){
		d[i]=read();
		if(d[i]==0)final[i]=1;
		for(int j=1;j<=d[i];++j){
			int s=read();
			adde(i,s);
		}
	}
	for(int i=1;i<=m;++i){
		fs t;
		t.fm=1;
		t.fz=1;
		ans[i]=t;
	}
	for(int i=m+1;i<=n;++i){
		fs t;
		t.fm=1;
		t.fz=0;
		ans[i]=t;
	}
	for(int i=1;i<=m;++i){
		if(!vis[i]){
			bfs(i);
		}
	}
	for(int i=1;i<=n;++i){
		if(final[i]){
			cout<<ans[i].fz<<" "<<ans[i].fm<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

