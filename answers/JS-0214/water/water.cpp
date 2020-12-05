#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

struct Edge{
	int v,next;
}e[2*maxn];

int n,m,tot;
int head[maxn],d[maxn],deg[maxn];
bool vis[maxn];
pii val[maxn];
vector<int> tp;

int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		int id=ch-'0';
		s=s*10+id;
		ch=getchar();
	}
	return s*w;
}

void add(int a,int b){
	e[++tot].next=head[a];
	e[tot].v=b;
	head[a]=tot;
}

void topo(){
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(!deg[i]){
			q.push(i);
			tp.pb(i);
			vis[i]=true;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			if(vis[v]) continue;
			--deg[v];
			if(!deg[v]){
				q.push(v);
				vis[v]=true;
				tp.pb(v);
			}
		}
	}
}

pii Add(pii a,pii b){
	int u1=a.first,u2=b.first,v1=a.second,v2=b.second;
	int v=v1*v2;
	int u=u1*v2+u2*v1;
	pii res=make_pair(u,v);
	return res;
}

int gcd(int a,int b){
	if(a<b) swap(a,b);
	if(b==0) return a;
	if(b==1) return 1ll;
	return gcd(b,a%b);
}

pii Smp(pii a){
	int x=a.first,y=a.second;
	int Div=gcd(x,y);
	x/=Div;
	y/=Div;
	pii res=make_pair(x,y);
	return res;
}

signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		d[i]=read();
		for(int j=1;j<=d[i];++j){
			int a=read();
			add(i,a);
			++deg[a];
		}
	}
	for(int i=1;i<=n;++i){
		if(!deg[i]) val[i]=make_pair(1,1);
		else val[i]=make_pair(0,1);
	}
	topo();
	for(int i=0;i<tp.size();++i){
		int p=tp[i];
		pii D=val[p];
		D.second*=d[p];
		for(int j=head[p];j;j=e[j].next){
			int v=e[j].v;
			val[v]=Add(val[v],D);
			val[v]=Smp(val[v]);
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]==0){
			val[i]=Smp(val[i]);
			cout<<val[i].first<<" "<<val[i].second<<endl;
		}
	}
	return 0;
}
